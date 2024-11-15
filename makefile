CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC
INCLUDES = -Iinclude

SOURCES = src/platform.cpp src/station.cpp src/line.cpp
OBJECTS = platform.o station.o line.o
LIB = libRailwayLibrary.so


all: $(LIB) main

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

$(LIB): $(OBJECTS)
	$(CXX) -shared -o $@ $(OBJECTS)

main: main.cpp $(LIB)
	$(CXX) $(CXXFLAGS) $(INCLUDES) main.cpp -L. -lRailwayLibrary -o main

clean:
	rm -f $(OBJECTS) $(LIB) main

.PHONY: all clean
