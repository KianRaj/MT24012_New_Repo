Indian Railways Library Assignment
This Assignment implements a C++ library for Indian Railways that models stations, lines, and platforms. The system allows for the dynamic handling of train stoppages, ensuring that platforms can accommodate trains based on their type (regular or through trains).

Overview
The library includes:

Stations: Represented with either an integer or string ID.
Platforms: Each station has platforms, which have time slots for train stoppages. Regular trains can stop every 30 minutes, while through trains can stop every 10 minutes.
Lines: A line consists of multiple stations.
The project follows object-oriented principles, including:

Polymorphism: Different station types (integer vs string ID) handled polymorphically.
Data Hiding: Proper encapsulation of data.
Exception Handling: Ensures that incorrect data is not accepted.
Requirements
C++17 or later.
g++ compiler.
make for building the project.
Project Structure
makefile
Copy code
/RailwayLibraryProject
├── Makefile           # Makefile for building the project (static & shared libraries)
├── README.md          # This readme file
├               # C++ source files
│── main.cpp
│── station.cpp
│── platform.cpp
│── line.cpp
├── include/           # Header files
│── station.hpp
│── platform.hpp
│── line.hpp
├── obj/               # Object files will be placed here
├── bin/               # Executables will be placed here
├── lib/               # Compiled libraries will be placed here
└── .gitignore         # Ignored files for version control
Building the Project
1. Clone the repository:
bash
Copy code
git clone https://github.com/KianRaj
cd Indian-Railways-Library
2. Build the project using the provided Makefile:
To build everything (static and shared libraries, debug and optimized versions):
bash
Copy code
make
To build the debug version only:
bash
Copy code
make debug
To build the optimized version only:
bash
Copy code
make optimized
To clean up object files, libraries, and executables:
bash
Copy code
make clean
Output:
The Makefile will generate:
libRailwayLibrary.a: The static library.
libRailwayLibrary.so: The shared library.
main-debug: The debug version of the test program.
main-optimized: The optimized version of the test program.
Executables will be placed in the bin/ directory.
Usage
Test Program:
Once the project is built, you can run the test program:

For Debug Version:

bash
Copy code
./bin/main-debug
For Optimized Version:

bash
Copy code
./bin/main-optimized
Menu Options:
The test program will present a menu with the following options:

Test Platform Time Availability: Enter platform details (ID, arrival time, departure time) and check if a train can stop at a requested time.
Test Add Station and Platform: Add stations and platforms to the railway system, and check if the station can accommodate the platform.
Test Exceed Platform Limit: Attempt to add more platforms than allowed to test platform limit functionality.
Test Invalid Station ID: Test the handling of invalid station IDs.
Exit: Exit the program.
Example Input for Platform Availability Test:
vbnet
Copy code
Enter platform ID, arrival time (minutes from midnight), departure time (minutes from midnight), and whether it's through (y/n):
1 600 630 y
Enter requested time (in minutes from midnight): 610
Platform is available for the requested time.
Input Format
For the test cases:
Station ID: Can be either an integer or a string.
Platform:
Arrival Time and Departure Time: Specified in minutes from midnight.
Through Train: (y/n) – Indicating whether the platform is for through trains (if y, 10-minute intervals are allowed; if n, 30-minute intervals are allowed).
For invalid station IDs, an exception will be thrown if an empty or incorrect ID is entered.
Libraries and Dependencies
The project uses standard C++17 features, such as exception handling, polymorphism, and dynamic memory management.
The Makefile handles the compilation of both static (.a) and shared (.so) libraries, allowing flexibility in how the library is linked with the test program.
Exception Handling
The library has been designed to ensure that:

Invalid input (such as incorrect station ID or time format) is rejected.
Platform limits are enforced correctly.
Error messages are displayed for incorrect actions, ensuring proper feedback to the user.
Git Repository
At least 4 significant commits have been made to track the development of the project.
GitHub is used for version control. You can find the repository at: https://github.com/KianRaj/MT24012_New_Repo
Submission
Submit the code repository on GitHub, ensuring that the TA is made an admin of the repository.
Submit the code as a zip file on Google Classroom by the due date.

