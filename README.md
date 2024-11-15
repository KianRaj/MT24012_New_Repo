<<<<<<< HEAD
Railway System Library
Build Instructions
Prerequisites

G++ compiler with C++17 support
Make build system

Building the Project

Build the entire project using Make:

bashCopymake
This will:

Compile the source files (platform.cpp, station.cpp, line.cpp) into object files
Create a static library libRailwayLibrary.a
Compile and link the main program

Manual Build Commands
If you need to build manually, use these commands:
bashCopy# Compile source files
g++ -Wall -Wextra -std=c++17 -c platform.cpp -o platform.o
g++ -Wall -Wextra -std=c++17 -c station.cpp -o station.o
g++ -Wall -Wextra -std=c++17 -c line.cpp -o line.o

# Create static library
ar rcs libRailwayLibrary.a platform.o station.o line.o

# Compile and link main program
g++ -Wall -Wextra -std=c++17 -Iinclude main.cpp -L. -lRailwayLibrary -o main
Input File Formats
Station File Format
Each line represents a station with the following format:
CopyStationID,StationName,NumberOfPlatforms
Example:
Copy1,Central Station,5
2,North Terminal,3
Line File Format
Each line represents a railway line with the following format:
CopyLineName:Station1,Station2,Station3,...
Example:
CopyRed Line:1,2,3,4
Blue Line:2,5,6,1
Platform File Format
Each line represents a platform with the following format:
CopyStationID,PlatformNumber,Length,HasOverheadLine
Example:
Copy1,1,200,true
1,2,150,false
Code Attribution
This project is original work, using standard C++ libraries and following object-oriented design principles taught in class. The file parsing logic was inspired by examples from:

C++ Reference Documentation (https://en.cppreference.com)

Project Structure
Copy.
├── include/         # Header files
├── src/            # Source files
├── main.cpp        # Main program
├── Makefile        # Build configuration
└── README.md       # This file
Notes

Input files must be in the specified format to be parsed correctly
All station IDs must be unique integers
Line names must be unique strings
Platform numbers must be unique within each station

<<<<<<< HEAD
=======

>>>>>>> 2027be5bd8ba80401ab9699c34b33061c3b67b7e
