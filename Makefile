all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test1: all
	bin/gauss dane/A2 dane/b2

test2: all
	bin/gauss dane/A3 dane/b3

test3: all
	bin/gauss dane/A4 dane/b4

test4: all
	bin/gauss dane/A5 dane/b5


