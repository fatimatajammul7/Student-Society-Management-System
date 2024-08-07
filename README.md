# Student Society Management System

This project demonstrates the implementation of a basic Student Society Management System using C++. The system allows for managing student society members, appointing a president, and performing various operations such as adding and suspending members.

## Features

- **Student Management**: Create and manage student records with name, roll number, and CGPA.
- **Society Management**: Manage a society, including appointing a president and adding/suspending members.
- **Membership Criteria**: Only students with a CGPA greater than 3.00 can be appointed as president.
- **Dynamic Member Handling**: Handle up to 5 members per society, with operations to add and remove members.

## Compilation Instructions

To compile and run the file, follow these instructions:

1. **Ensure you have a C++ compiler installed** (e.g., g++, clang++).

2. **Compile the code** using the following command:
   ```bash
   g++ -o program Code.cpp
3. **Run the executable with the following command:**
   ```bash
   ./program

## Example Usage

This program showcases the following functionalities:

- **Appointing a President**: A student with a CGPA greater than 3.00 can be appointed as the president of the society.
- **Adding Members**: Students can be added to the society, provided they are not already a member and are not the president.
- **Suspending a Member**: A member can be suspended from the society based on their name.
- **Displaying Information**: The `PrintInfo()` method provides a detailed overview of the society, including the current president and all members.

## Notes

- The program utilizes static methods for string comparison and dynamic memory management.
- Proper handling of memory management is crucial to avoid memory leaks.
- The `PrintInfo()` method offers a comprehensive view of the society's current state, including the president and members.


If you encounter any issues or have questions, please feel free to reach out for assistance. Happy coding!
   
