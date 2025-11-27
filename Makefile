CPP_SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJ = $(CPP_SOURCES:.cpp=.o)

all: main

main: $(OBJ)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -f *.o main

.PHONY: all clean
