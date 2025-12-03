CPP_SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJ = $(CPP_SOURCES:.cpp=.o)

all: main

main: $(OBJ)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -std=c++17 -c $< -o $@

clean:
	rm -f *.o main

.PHONY: all clean
