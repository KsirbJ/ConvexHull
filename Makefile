
flags = -g -Wall -std=c++11


all:	convexhull

convexhull:	main.o
	g++ $(flags) main.o -o convexhull

main.o:	main.cpp
	g++ -c $(flags) main.cpp

giftwrapping.o:	giftwrapping.cpp
	g++ -c $(flags) giftwrapping.cpp

grahamscan.o:	grahamscan.cpp
	g++ -c $(flags) grahamscan.cpp


test: generator.c convexhull
	gcc generator.c -o gen
	./gen -n 1000 -m 1 -M 10000 -o 1kx.txt
	./gen -n 1000 -m 1 -M 10000  -o 1ky.txt
	./gen -n 10000 -m 1 -M 10000  -o 10kx.txt
	./gen -n 10000 -m 1 -M 10000  -o 10ky.txt
	./gen -n 50000 -m 1 -M 10000  -o 50kx.txt
	./gen -n 50000 -m 1 -M 10000  -o 50ky.txt
	./gen -n 100000 -m 1 -M 10000  -o 100kx.txt
	./gen -n 100000 -m 1 -M 10000  -o 100ky.txt
	./gen -n 250000 -m 1 -M 10000  -o 250kx.txt
	./gen -n 250000 -m 1 -M 10000  -o 250ky.txt
	./gen -n 400000 -m 1 -M 10000  -o 400kx.txt
	./gen -n 400000 -m 1 -M 10000  -o 400ky.txt
	./gen -n 550000 -m 1 -M 10000  -o 550kx.txt
	./gen -n 550000 -m 1 -M 10000  -o 550ky.txt
	./gen -n 700000 -m 1 -M 10000  -o 700kx.txt
	./gen -n 700000 -m 1 -M 10000  -o 700ky.txt
	./gen -n 850000 -m 1 -M 10000  -o 850kx.txt
	./gen -n 850000 -m 1 -M 10000  -o 850ky.txt
	./gen -n 1000000 -m 1 -M 10000  -o 1mx.txt
	./gen -n 1000000 -m 1 -M 10000  -o 1my.txt
	./convexhull

clean:
	rm -f *.o *.txt *.out gen convexhull
