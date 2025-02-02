
---

# PC Registration System

This project is a C++ based system for managing and registering PCs for users in an organization. The system is designed to handle different user types (Admin, Staff, Non-Staff, and Student) and provides functionality for managing the database, authentication, and user interactions via menus. It is connected to a PostgreSQL database with a secured environment using the `.env` configuration file.

## Features

- **User Authentication**: Users (Admin, Staff, Non-Staff, Student) can log in with secure credentials.
- **Admin Role**: Admin users can perform high-level operations and manage system settings.
- **User Management**: Manage users, view details, and assign resources.
- **PostgreSQL Database Integration**: All data is stored in a PostgreSQL database, including user information and login credentials.
- **Environment Security**: Sensitive data like database credentials are stored in a `.env` file to ensure security.
- **Menu System**: A dynamic menu-driven interface allows users to navigate between various system functionalities based on their role.

---

## Project Structure

Here’s an overview of the project directory structure:

```
c++/
├── models/
│   ├── admin/
│   │   └── admin.h
│   ├── users/
│   │   ├── staff.h
│   │   ├── non_staff.h
│   │   └── student.h
├── database/
│   ├── admin/
│   │   └── AdminDBOperations.cpp
│   │   └── AdminDBOperations.h
│   ├── user/
│   │   ├── non_staff/
│   │   │   ├── NonstaffDBOperations.h
│   │   │   └── NonstaffDBOperations.cpp
│   │   ├── staff/
│   │   │   ├── staffDBOperation.h
│   │   │   └── staffDBOperation.cpp
│   │   ├── student/
│   │   │   ├── StudentDBOperations.h
│   │   │   └── StudentDBOperations.cpp
│   ├── connection.cpp
│   ├── connection.h
│   ├── dotenv.cpp
│   ├── dotenv.h
├── middleware/
│   ├── input_validation.h
│   ├── input_validation.cpp
├── services/
│   ├── admin/
│   │   ├── AdminService.h
│   │   └── AdminService.cpp
│   ├── user/
│   │   ├── non_staff_service.h
│   │   ├── non_staff_service.cpp
│   │   ├── staff_service.h
│   │   ├── staff_service.cpp
│   │   ├── student_service.h
│   │   └── student_service.cpp
│   ├── auth/
│   │   ├── auth_service.h
│   │   └── auth_service.cpp
├── menus/
│   ├── main_menu.cpp
│   ├── sub_menus/
│   │   ├── super_admin_menu/
│   │   │   ├── super_admin_menu.h
│   │   │   └── super_admin_menu.cpp
│   │   ├── admin_menu/
│   │   │   ├── admin_menu.h
│   │   │   └── admin_menu.cpp
│   │   ├── user_menu/
│   │   │   ├── user_menu.h
│   │   │   └── user_menu.cpp
│   │   ├── staff_menu/
│   │   │   ├── staff_menu.h
│   │   │   └── staff_menu.cpp
│   │   ├── non_staff_menu/
│   │   │   ├── non_staff_menu.h
│   │   │   └── non_staff_menu.cpp
│   │   └── student_menu/
│   │       ├── student_menu.h
│   │       └── student_menu.cpp
```

### Key Folders and Files

1. **models/**: Contains header files for the definitions of user models (`admin.h`, `staff.h`, `student.h`, etc.).
2. **database/**: Includes database-related files, such as connection handling (`connection.h`, `dotenv.h`) and operations for each user type (`AdminDBOperations.cpp`, `StudentDBOperations.cpp`, etc.).
3. **middleware/**: Contains files for input validation (`input_validation.h`, `input_validation.cpp`).
4. **services/**: Defines the service layer, where the main business logic resides. It includes services for managing users and authentication.
5. **menus/**: Contains menu systems for different users (admin, staff, etc.). This handles the display of the menus and navigations.

---

## Requirements

- C++ compiler (e.g., g++)
- PostgreSQL installed on your machine
- `libpqxx` (C++ library for PostgreSQL)
- `.env` file to store your database credentials securely

---

## Setup and Installation

### 1. Clone the repository

```bash
git clone https://github.com/Yabe12/PC_Registration_System.git
cd c++
```

### 2. Install PostgreSQL and libpqxx

Make sure you have PostgreSQL installed on your system and the required C++ library `libpqxx` for connecting to the database.

- On Ubuntu:

```bash
sudo apt-get install libpqxx-dev
```

- On macOS:

```bash
brew install libpqxx
```

### 3. Create a PostgreSQL Database

Create a PostgreSQL database and a user with appropriate permissions.

```bash
psql -U postgres
CREATE DATABASE pc_registration_system;
CREATE USER <username> WITH PASSWORD '<password>';
ALTER ROLE <username> SET client_encoding TO 'utf8';
ALTER ROLE <username> SET default_transaction_isolation TO 'read committed';
ALTER ROLE <username> SET timezone TO 'UTC';
GRANT ALL PRIVILEGES ON DATABASE pc_registration_system TO <username>;
```

### 4. Configure the `.env` File

Create a `.env` file at the root of the project directory and add the following:

```bash
DB_HOST=localhost
DB_PORT=5432
DB_NAME=pc_registration_system
DB_USER=<username>
DB_PASSWORD=<password>
```

### 5. Compile the Code

Compile the C++ files using a C++ compiler such as `g++`.

```bash
g++ menus/main_menu.cpp services/auth_service.cpp menus/sub_menus/super_admin_menu/super_admin_menu.cpp menus/sub_menus/admin_menu/admin_menu.cpp services/admin/AdminService.cpp menus/sub_menus/user_menu/user_menu.cpp menus/sub_menus/staff_menu/staff_menu.cpp menus/sub_menus/non_staff_menu/non_staff_menu.cpp menus/sub_menus/student_menu/student_menu.cpp services/user/non_staff_service.cpp services/user/staff_service.cpp services/user/student_service.cpp database/admin/AdminDBOperations.cpp  database/superadmin/SuperAdminDBOperations.cpp database/user/non_staff/NonstaffDBOperations.cpp database/user/staff/staffDBOperation.cpp database/user/student/StudentDBOperations.cpp database/connection.cpp database/dotenv.cpp middleware/input_validation.cpp -o database/app.exe -I"C:/Program Files/PostgreSQL/16/include" -L"C:/Program Files/PostgreSQL/16/lib" -lpq
```

### 6. Run the System

```bash
./pc_registration_system
```

The application will now connect to your PostgreSQL database and allow users to interact with the system.

---

## How to Use

1. **Login**: Users will be prompted to login using their credentials. The system will validate the user role (Admin, Staff, Non-Staff, or Student).
2. **Navigate Menus**: Based on the logged-in user’s role, the relevant menu will be displayed.
3. **Perform Actions**: Admins can manage system settings, staff, students, and more, while other roles can perform specific tasks related to their access level.

---

## Database Schema

The database schema contains tables for each type of user (Admin, Staff, Non-Staff, and Student) and their associated data. The system also includes a table for user roles and login credentials.

Example schema for `users`:

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    role VARCHAR(50) NOT NULL
);
```

### Sample Queries

- Add a new user:
  ```sql
  INSERT INTO users (username, password, role) VALUES ('admin', 'securepassword', 'admin');
  ```

- Fetch all users:
  ```sql
  SELECT * FROM users;
  ```

---

## Contributing

If you would like to contribute to this project, feel free to fork the repository, make your changes, and create a pull request. Please ensure your code adheres to the existing coding standards and passes any existing tests.

---

## License

This project is open-source and available under the MIT License.

---

