Indian Railways Library
This library is designed to manage the functionality of the Indian Railways system, specifically handling stations, lines, and platforms.
Assignment Details
This assignment carries a total of 60 marks, with the following components:

Class Design and Implementation (40 marks):

The library must have classes for (i) stations, (ii) lines, and (iii) platforms.
Each station is associated with multiple lines, corresponding to a single platform.
A single platform can only accommodate a train stoppage once every 30 minutes, whereas a through train can be accommodated once every 10 minutes.
The station's ID can be either a string or an integer, depending on the user program's preference.
The principles of polymorphism and data hiding must be followed in the library.
Incorrect information coming from the user program must be rejected.


Test User Program (20 marks):

Write a test user program to verify the functionality of the library.
The test program should demonstrate that both correct data is accepted and incorrect data is rejected.
Any data structure from the C++ library can be used.



Library Design
Class Structure

Station Class:

Handles the information about a specific station, including its ID (string or integer), name, and associated lines.
Provides methods to add, remove, and retrieve lines associated with the station.
Ensures that a platform can only accommodate a train stoppage once every 30 minutes or a through train once every 10 minutes.


Line Class:

Represents a specific railway line, with a unique ID (string or integer) and a list of stations along the line.
Provides methods to add, remove, and retrieve stations along the line.


Platform Class:

Encapsulates the functionality of a platform associated with a station.
Tracks the train timings and ensures that the platform rules are followed (30 minutes for stoppage, 10 minutes for through train).
Provides methods to schedule train arrivals and departures, and to check the availability of the platform.



The library should follow the principles of polymorphism and data hiding to ensure that the user program cannot directly access or modify the internal implementation details of the classes.
Test User Program
The test user program should demonstrate the following scenarios:

Correct Data Acceptance:

Create stations with both string and integer IDs.
Add lines to the stations and verify the associations.
Schedule train arrivals and departures on the platforms and ensure that the platform rules are followed.


Incorrect Data Rejection:

Attempt to schedule a train arrival or departure that violates the platform rules (e.g., less than 30 minutes for a stoppage, less than 10 minutes for a through train).
Verify that the library rejects the invalid input and provides appropriate error messages.



The test program should use a variety of data structures from the C++ library (e.g., std::vector, std::map, std::set) to manage the railway system entities and demonstrate the library's functionality.
Submission Instructions

Ensure that your code follows the design requirements and includes the necessary classes, methods, and error handling.
Create a README file (this document) that provides a clear and detailed overview of the assignment, the library design, and the test user program.
Submit your code, including the library implementation and the test user program, along with the README file.



