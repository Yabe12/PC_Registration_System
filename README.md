# PC Registration System Backend Code Structure

This document outlines the folder structure and components of the backend code for a PC Registration System. The system is designed to connect to a database and can be expanded to include a GUI in the future. The focus is on the backend logic, ensuring scalability, maintainability, and clarity.

---

## **Folder Structure Overview**

```
---
project-root/
├── controllers/
│   ├── admin/
│   │   └── admin_controller.cpp
│   ├── users/
│   │   ├── student_controller.cpp
│   │   ├── staff_controller.cpp
│   │   └── non_staff_controller.cpp
│   └── authentication_controller.cpp
│
├── database/
│   ├── db_connection.cpp
│   └── migrations/
│       ├── create_users_table.sql
│       ├── create_students_table.sql
│       ├── create_staff_table.sql
│       └── create_admins_table.sql
│
├── middleware/
│   ├── auth_middleware.cpp
│   └── input_validation.cpp
│
├── models/
│   ├── admin/
│   │   └── admin.cpp
│   ├── users/
│   │   ├── student.cpp
│   │   ├── staff.cpp
│   │   └── non_staff.cpp
│   └── base_model.cpp
│
├── services/
│   ├── admin/
│   │   └── admin_service.cpp
│   ├── users/
│   │   ├── student_service.cpp
│   │   ├── staff_service.cpp
│   │   └── non_staff_service.cpp
│   └── auth_service.cpp
│
├── utils/
│   ├── logger.cpp
│   ├── config_loader.cpp
│   ├── error_handler.cpp
│   └── constants.h
│
├── menus/
│   ├── main_menu.cpp
│   └── sub_menus/
│       ├── admin_menu.cpp
│       ├── student_menu.cpp
│       ├── staff_menu.cpp
│       └── non_staff_menu.cpp
│
├── tests/
│   ├── controllers/
│   ├── services/
│   ├── models/
│   └── utils/
│
├── .env
├── .gitignore
├── CMakeLists.txt
├── main.cpp
└── README.md
```

### Purpose of Each Directory and Files
#### **`controllers/`**
Handles user requests, processes them, and sends responses. Each role (admin, student, staff) has its dedicated controller.

#### **`database/`**
Contains the database connection logic (`db_connection.cpp`) and migration files (`.sql`) for creating and managing database tables.

#### **`middleware/`**
Contains reusable logic like authentication and input validation (`auth_middleware.cpp`, `input_validation.cpp`).

#### **`models/`**
Represents the database entities. Includes base class (`base_model.cpp`) for common database operations.

#### **`services/`**
Implements the business logic for each entity. Separate services handle functionality for admins, students, and staff.

#### **`utils/`**
Holds utility functions such as logging, error handling, and loading configuration (`logger.cpp`, `config_loader.cpp`).

#### **`menus/`**
Manages user interaction and menu navigation (`main_menu.cpp` and `sub_menus` for specific roles).

#### **`tests/`**
Organizes unit and integration tests for each layer of your application.
---

## **Development Notes**

- **Scalability**: The modular design ensures ease of scalability and facilitates the addition of new features without disrupting the existing codebase.
- **Maintainability**: Separation of concerns through distinct folders for models, services, and utilities makes the system easy to maintain and debug.
- **Security**: Sensitive information is stored securely in the `.env` file, and middleware ensures data validation and sanitization.
- **Future Expansion**: While the current focus is backend development, the system can easily integrate a GUI in the future, leveraging the existing service layer.

---

