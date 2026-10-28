"""Build the course examples and each HW6 implementation variant."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]


def targets(directory, entry):
    for parent in sorted({p.parent for p in directory.rglob(entry)}):
        sources = sorted(parent.glob('*.cpp'))
        mains = [p for p in sources if p.name.startswith('main')]
        support = [p for p in sources if p not in mains]
        variants = sorted((parent / 'variants').glob('*.cpp'))
        for main in [p for p in mains if p.name == entry]:
            for variant in variants or [None]:
                label = parent.relative_to(ROOT).as_posix()
                if main.stem != 'main':
                    label += '/' + main.stem
                if variant is not None:
                    label += '/' + variant.stem
                yield label, parent, [main, *support, *([variant] if variant else [])]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', nargs='?', default='.')
    parser.add_argument('--cxx', default=os.environ.get('CXX', 'g++'))
    parser.add_argument('--entry', default='main.cpp', help='Entry source file name (default: main.cpp).')
    args = parser.parse_args()
    directory = (ROOT / args.directory).resolve()
    if directory != ROOT and ROOT not in directory.parents:
        parser.error('Choose a directory inside this repository.')
    if not directory.is_dir():
        parser.error('Directory does not exist.')
    compiler = shutil.which(args.cxx)
    if compiler is None:
        parser.error('C++ compiler not found; set CXX or pass --cxx.')
    output = ROOT / 'build'
    output.mkdir(exist_ok=True)
    jobs = list(targets(directory, args.entry))
    if not jobs:
        parser.error(f'No {args.entry} programs in this directory.')

    def build(job):
        label, parent, sources = job
        executable = output / (label.replace('/', '__') + ('.exe' if os.name == 'nt' else ''))
        command = [compiler, '-std=c++17', '-I', str(parent), *map(str, sources), '-o', str(executable)]
        result = subprocess.run(command, cwd=parent, capture_output=True, text=True, errors='replace', timeout=90)
        return {'target': label, 'exit_code': result.returncode, 'command': command,
                'diagnostics': result.stdout + result.stderr}

    with ThreadPoolExecutor(max_workers=4) as pool:
        results = list(pool.map(build, jobs))
    for result in results:
        print(('OK   ' if result['exit_code'] == 0 else 'FAIL ') + result['target'])
        if result['exit_code']:
            print(result['diagnostics'])
    (output / 'build-results.json').write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding='utf-8')
    failed = sum(result['exit_code'] != 0 for result in results)
    print(f'{len(results) - failed}/{len(results)} programs built')
    return bool(failed)


if __name__ == '__main__':
    sys.exit(main())
