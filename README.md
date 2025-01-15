# PC Registration System

## Overview
The **PC Registration System** is a console-based application designed to manage the registration of computers used by students, staff, and non-staff members. It allows users to add, search, delete, and update records efficiently using a **doubly linked list** data structure. The system is implemented in both **C++ and Java**.

## Features
- **Register PCs**: Supports adding students, staff, and non-staff along with their PC details.
- **Search Records** (Feature to be implemented)
- **Delete Records** (Feature to be implemented)
- **Update Records** (Feature to be implemented)
- **Console-Based Menu**: Provides an interactive menu for user operations.

## Data Structures Used
The system uses **doubly linked lists** to manage user data:
- `student`: Stores student details along with their PC information.
- `staff`: Stores staff details along with their PC information.
- `nonstaff`: Stores non-staff details along with their PC information.

Each class (Java) or struct (C++) contains:
- **Personal Information**: Name, ID, gender, and phone number.
- **PC Information**: Computer name, serial number, and model.
- **Linked List Pointers**: `next` and `prev` for navigation.

## Getting Started
### Prerequisites
- A C++ compiler (e.g., g++ for GCC, MSVC for Visual Studio, or Clang)
- A Java Development Kit (JDK)

### Compilation and Execution
#### C++
To compile the C++ version of the project, use:
```sh
g++ pc_registration.cpp -o pc_registration
```
To run the compiled program:
```sh
./pc_registration
```

#### Java
To compile the Java version of the project, use:
```sh
javac PcRegistration.java
```
To run the compiled program:
```sh
java PcRegistration
```

## Usage
1. **Choose an option from the menu**
   - Register a PC (students, staff, or non-staff)
   - Search for a record (to be implemented)
   - Delete a record (to be implemented)
   - Update record details (to be implemented)
   - Exit the program

2. **Enter user and PC details** as prompted.
3. **The system stores the information** using a doubly linked list in memory.

## Known Issues & Bugs
- `add_user` mistakenly calls `add_staff` instead of `add_nonstaff`.
- Some variables like `char id`, `char department`, and `char model` should be `char arrays` or `strings` for proper data handling in C++.
- No functions for searching, deleting, and updating users yet.
- Missing proper linked list implementation to store multiple entries.
- Java version needs to fully replicate C++ features.

## Future Improvements
- Implement linked list traversal for storing and retrieving multiple records.
- Add search, update, and delete functionalities.
- Improve input validation and error handling.
- Enhance data persistence with file storage.
- Improve Java version to match C++ functionality.

## Contributions
Contributions are welcome! Feel free to fork this project, report issues, or suggest improvements.

## License
This project is open-source and free to use under the MIT License.


## Author
Developed by [**Fitsum helina**](https://github.com/Fitsumhelina) , [**Yeabsira Behailu**](https://www.linkedin.com/in/yeabsira-behailu-19504b285/) , [**Kisanet Hailemariam**](https://www.linkedin.com/in/kisanet-hailemariam-2118642a9/) .


