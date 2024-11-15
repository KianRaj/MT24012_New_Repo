# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC  # -fPIC for shared library

# Files
SOURCES = main.cpp line.cpp platform.cpp station.cpp
OBJECTS = main.o line.o platform.o station.o
STATIC_LIB = libRailwayLibrary.a
SHARED_LIB = libRailwayLibrary.so

# Targets
all: main $(STATIC_LIB) $(SHARED_LIB)

# Build static library
$(STATIC_LIB): line.o platform.o station.o
	ar rcs $@ $^

# Build shared library
$(SHARED_LIB): line.o platform.o station.o
	$(CXX) -shared -o $@ $^

# Build the executable using the static library
main: $(OBJECTS) $(STATIC_LIB)
	$(CXX) $(OBJECTS) -L. -lRailwayLibrary -o $@

# Compile .cpp files to .o objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean all build artifacts
clean:
	rm -rf *.o $(STATIC_LIB) $(SHARED_LIB) main

.PHONY: all clean
