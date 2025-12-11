CPP_SOURCES = main.cpp  
HEADERS = $(wildcard *.hpp io/evenement/* io/observateur/* io/*)
OBJ = $(CPP_SOURCES:.cpp=.o)

FLAGS = -std=c++17 -Wall 

all: main

main: $(OBJ)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f *.o main

.PHONY: all clean
