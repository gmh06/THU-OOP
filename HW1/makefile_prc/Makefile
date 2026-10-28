all: main

main: main.cpp sum.cpp product.cpp functions.h
	g++ main.cpp sum.cpp product.cpp -o main

debug: main.cpp sum.cpp product.cpp functions.h
	g++ -g -D DEBUG main.cpp sum.cpp product.cpp -o main

clean:
	rm main