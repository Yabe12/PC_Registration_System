# PC Registration System Backend Code Structure

This document outlines the folder structure and components of the backend code for a PC Registration System. The system is designed to connect to a database and can be expanded to include a GUI in the future. The focus is on the backend logic, ensuring scalability, maintainability, and clarity.

---

## **Folder Structure Overview**

```
project-root/
├── menu/
│   ├── admin_menu/
│   ├── super_admin_menu/
│   └── main_menu/
├── model/
│   ├── users/
│   │   ├── student/
│   │   ├── non_staff/
│   │   └── staff/
├── service/
│   ├── admin/
│   ├── users/
│   │   ├── student/
│   │   ├── non_staff/
│   │   └── staff/
├── utils/
│   ├── algorithms/
│   │   ├── sorting.cpp
│   │   └── searching.cpp
│   ├── display/
│   ├── logs/
│   ├── backups/
│   └── reports/
├── middleware/
│   └── input_validation/
├── controller/
│   └── authentication/
├── .env
└── README.md
```

---

## **Folder Details**

### 1. **menu/**
Contains modules for managing different menu types within the system.
- **admin_menu/**: Code for displaying and handling admin-specific options.
- **super_admin_menu/**: Code for managing super admin operations.
- **main_menu/**: Entry point for the user, displaying the main menu options.

### 2. **model/**
Holds the structural representation of entities in the system. These are plain C++ classes that define attributes and relationships.
- **admin/**: Structure for the admin entity, including attributes like `id`, `name`, `role`, etc.
- **users/**: Structures for user-related entities:
  - **student/**: Attributes specific to students, such as `studentID`, `department`, etc.
  - **non_staff/**: Details about non-staff users, like `name`, `purpose`, etc.
  - **staff/**: Attributes related to staff, such as `employeeID`, `position`, etc.

### 3. **service/**
Contains the core implementation of the system’s functionality.
- **admin/**: Admin-specific operations, such as adding or removing PCs, managing permissions, etc.
- **users/**: User-specific operations categorized into:
  - **student/**: Services like registering a student, updating details, etc.
  - **non_staff/**: Non-staff-related services, such as creating or updating records.
  - **staff/**: Staff-related operations, like assigning or revoking PC access.

### 4. **utils/**
Utility functions and modules to support core functionalities.
- **algorithms/**:
  - **sorting.cpp**: Sorting algorithms for arranging data.
  - **searching.cpp**: Searching algorithms for retrieving data efficiently.
- **display/**: Functions for formatting and presenting data.
- **logs/**: Logging mechanisms for tracking system activities.
- **backups/**: Code for managing backups of the database or critical files.
- **reports/**: Functions to generate reports for administrators or users.

### 5. **middleware/**
Contains logic for handling input validation and pre-processing.
- **input_validation/**: Ensures inputs adhere to expected formats (e.g., validating phone numbers, email addresses, etc.).

### 6. **controller/**
Handles high-level application logic and orchestrates between models, services, and utilities.
- **authentication/**: Verifies credentials for admins and super admins, ensuring secure access to sensitive functionalities.

### 7. **.env**
Stores sensitive configuration data such as database credentials, API keys, and environment-specific variables. This file should never be committed to version control.

---

## **Development Notes**

- **Scalability**: The modular design ensures ease of scalability and facilitates the addition of new features without disrupting the existing codebase.
- **Maintainability**: Separation of concerns through distinct folders for models, services, and utilities makes the system easy to maintain and debug.
- **Security**: Sensitive information is stored securely in the `.env` file, and middleware ensures data validation and sanitization.
- **Future Expansion**: While the current focus is backend development, the system can easily integrate a GUI in the future, leveraging the existing service layer.

---

