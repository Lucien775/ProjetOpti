CPP_SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

CPP_NO_MAIN = $(filter-out main.cpp, $(CPP_SOURCES))
OBJ = $(CPP_NO_MAIN:.cpp=.o)

all: main

main: main.cpp $(OBJ)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -f *.o main

.PHONY: all clean
