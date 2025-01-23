// // --- services/user_service.cpp ---
// #include <iostream>
// #include <pqxx/pqxx>
// #include "../database/db_connection.cpp"

// class UserService {
// public:
//     static void addStudent() {
//         std::string name, department;
//         int age;
//         std::cout << "Enter name: ";
//         std::cin >> name;
//         std::cout << "Enter age: ";
//         std::cin >> age;
//         std::cout << "Enter department: ";
//         std::cin >> department;

//         try {
//             auto conn = Database::connect();
//             pqxx::work txn(*conn);
//             txn.exec0("INSERT INTO students (name, age, department) VALUES (" + txn.quote(name) + ", " + txn.quote(age) + ", " + txn.quote(department) + ")");
//             txn.commit();
//             std::cout << "Student added successfully!\n";
//         } catch (const std::exception &e) {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
//     }

//     static void viewStudents() {
//         try {
//             auto conn = Database::connect();
//             pqxx::work txn(*conn);
//             pqxx::result result = txn.exec("SELECT * FROM students");

//             for (const auto& row : result) {
//                 std::cout << "ID: " << row["id"].c_str() << ", Name: " << row["name"].c_str() << ", Age: " << row["age"].as<int>() << ", Department: " << row["department"].c_str() << "\n";
//             }
//         } catch (const std::exception &e) {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
//     }
// };