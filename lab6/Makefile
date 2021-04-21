all: clean buildMain buildTest runTest

buildMain: main.cpp
	g++ -o main main.cpp tree.cpp

buildTest: test.cpp
	g++ -o test test.cpp tree.cpp

runTest:
	./test

clean:
	rm -rf *.exe