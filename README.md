# THU-OOP

[![CI](https://github.com/gmh06/THU-OOP/actions/workflows/ci.yml/badge.svg)](https://github.com/gmh06/THU-OOP/actions/workflows/ci.yml)

清华大学面向对象程序设计基础课程作业与考试练习。

## 内容

- `HW1/`：多文件编译、类与对象。
- `HW2/`：大整数、字符串与映射。
- `HW3/`：组合、继承与多态。
- `HW4/`：运算符重载与对象协作。
- `HW5/`：模板、容器、参数解析与查询。
- `HW6/`：设计模式与接口适配。
- `EXAM/`、`final/`：考试练习与不同版本实现。

## 编译

需要 Python 3 和支持 C++17 的编译器：

```bash
python scripts/build.py
python scripts/build.py HW5/ArgParser
```

默认编译各题的 `main.cpp`，程序输出到 `build/`。有 Makefile 的题目也可进入目录执行 `make`。
`HW6/ExploreSystem` 和 `HW6/Skill` 的五个实现位于 `variants/`，分别编译；使用 Makefile 时通过 `VERSION=1`–`5` 选择。

代码审查题的分析与源码放在同一目录。
