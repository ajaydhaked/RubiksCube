main: BaseCube.o BitCube.o main.cpp NibbleArray.o PatternDatabase.o CornerPatternDatabase.o CornerDBMaker.o math.o
	g++ BaseCube.o BitCube.o NibbleArray.o PatternDatabase.o CornerPatternDatabase.o math.o CornerDBMaker.o main.cpp -o main

BaseCube.o: BaseCube.cpp BaseCube.h
	g++ -c BaseCube.cpp -o BaseCube.o

BitCube.o: BaseCube.h BitCube.cpp
	g++ -c BitCube.cpp -o BitCube.o

NibbleArray.o: ./PatternDatabases/NibbleArray.cpp ./PatternDatabases/NibbleArray.h
	g++ -c ./PatternDatabases/NibbleArray.cpp -o NibbleArray.o

PatternDatabase.o: ./PatternDatabases/PatternDatabase.cpp ./PatternDatabases/PatternDatabase.h
	g++ -c ./PatternDatabases/PatternDatabase.cpp -o PatternDatabase.o

CornerPatternDatabase.o: ./PatternDatabases/CornerPatternDatabase.cpp ./PatternDatabases/CornerPatternDatabase.h
	g++ -c ./PatternDatabases/CornerPatternDatabase.cpp -o CornerPatternDatabase.o

CornerDBMaker.o: ./PatternDatabases/CornerDBMaker.cpp ./PatternDatabases/CornerDBMaker.h
	g++ -c ./PatternDatabases/CornerDBMaker.cpp -o CornerDBMaker.o
	
math.o: ./PatternDatabases/math.cpp ./PatternDatabases/math.h
	g++ -c ./PatternDatabases/math.cpp -o math.o

clean:
	rm -f *.o main
