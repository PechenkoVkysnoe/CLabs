all: clean buildMain buildTest runTest

buildMain: main.c
	gcc -o main main.c -std=c89 -lm

buildTest: test.c
	gcc -o test -Dmain=_main main.c test.c -std=c89 -lm

runTest:
	./test

clean:
	rm -rf *.exe