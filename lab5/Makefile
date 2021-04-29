all: clean buildMain buildTest runTest

buildMain: main.cpp
	g++ -o main main.cpp 

buildTest: test.cpp
	g++ -o test test.cpp 

runTest:
	./test
	
clean:
	rm -rf *.exe