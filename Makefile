CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lncurses

all: gameoflife

gameoflife: main.o
	$(CXX) $(CXXFLAGS) -o gameoflife main.o $(LIBS)

clean:
	rm -f *.o gameoflife

run: gameoflife
	./gameoflife
