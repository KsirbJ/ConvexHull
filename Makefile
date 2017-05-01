
flags = -g -Wall -std=c++11


all:	convexhull

convexhull:	main.o
	g++ $(flags) giftwrapping.o grahamscan.o -o convexhull

giftwrapping.o:	giftwrapping.cpp
	g++ -c $(flags) giftwrapping.cpp

grahamscan.o:	grahamscan.cpp
	g++ -c $(flags) grahamscan.cpp


test: generator.c
	gcc generator.c -o gen
	./gen -n 1000 -m 1 -M 10000 -o 1kx.txt
	./gen -n 1000 -m 1 -M 10000 -o 1ky.txt
	./gen -n 10000 -m 1 -M 10000 -o 10kx.txt
	./gen -n 10000 -m 1 -M 10000 -o 10ky.txt
	./gen -n 100000 -m 1 -M 100000 -o 100kx.txt
	./gen -n 100000 -m 1 -M 100000 -o 100ky.txt
	./gen -n 250000 -m 1 -M 100000 -o 250kx.txt
	./gen -n 250000 -m 1 -M 100000 -o 250kyy.txt
	./gen -n 500000 -m 1 -M 100000 -o 500kx.txt
	./gen -n 500000 -m 1 -M 100000 -o 500ky.txt
	./gen -n 750000 -m 1 -M 100000 -o 750kx.txt
	./gen -n 750000 -m 1 -M 100000 -o 750ky.txt
	./gen -n 1000000 -m 1 -M 100000 -o 1mx.txt
	./gen -n 1000000 -m 1 -M 100000 -o 1my.txt

clean:
	rm -f *.o *.txt *.out gen convexhull
