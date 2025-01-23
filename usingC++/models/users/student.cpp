// // --- models/users/student.cpp ---
// #include "../base_model.cpp"
// #include <string>

// class Student : public BaseModel {
// public:
//     void create(const std::string& name, int age, const std::string& department) {
//         try {
//             pqxx::work txn(*db);
//             txn.exec0("INSERT INTO students (name, age, department) VALUES (" + txn.quote(name) + ", " + txn.quote(age) + ", " + txn.quote(department) + ")");
//             txn.commit();
//             std::cout << "Student created successfully!\n";
//         } catch (const std::exception &e) {
//             std::cerr << "Error creating student: " << e.what() << std::endl;
//         }
//     }
// };

#include <iostream>

int main () {

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    student *next;
    student *prev;
};
student *student_head = NULL, *student_tall =NULL;

}