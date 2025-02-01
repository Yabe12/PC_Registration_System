#include <iostream>
#include <cstring>
#include "../../models/users/student.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/student/StudentDBOperations.h"
#include "./student_service.h"

using namespace std;

student* student_head = nullptr;
student* student_tall = nullptr;
const int MAX_LENGTH = 50;


// Function to add a new student
void add_student() {
  cout << "\n=============================================" << endl;
    cout << "          Add New Student" << endl;
    cout << "=============================================" << endl;
 student *new_student = new student;
    cout << "Enter student's name: ";
    cin>>new_student->name;
    if (!validateInput(new_student->name, MAX_LENGTH)) return;

    cout << "Enter student's ID: ";
     cin >> new_student->id;
    if (!validateInput(new_student->id, 50)) return;

    cout << "Enter student's gender (Male / Female): ";
      cin >> new_student->gender;
    if (!validateGender(new_student->gender)) return;

    cout << "Enter student's department: ";
     cin >> new_student->department;
    if (!validateInput(new_student->department, 50)) return;

    cout << "Enter student's phone number: ";
   cin >> new_student->phone;
    if (!validatePhoneNumber(new_student->phone)) return;
    cin.ignore();  // Ignore newline left in buffer

    cout << "Enter student's computer name: ";
    cin >> new_student->pcname;
    if (!validateInput(new_student->pcname, 50)) return;

    cout << "Enter student's computer serial number: ";
     cin >> new_student->serial;
    if (!validateInput( new_student->serial, 50)) return;
new_student->next =NULL;
  new_student->prev = student_tall;
  if(student_tall != NULL){student_tall->next =new_student;} student_tall=new_student;
  if(student_head == NULL){student_head=student_tall; 
  }
  cout << "The student is added in temporary storage "<<endl;
   cout << "Would you like to save it to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        if (add_student_to_db(new_student->name, new_student->id, new_student->gender, new_student->department, new_student->phone, new_student->pcname, new_student->serial)) {
            cout << "Admin successfully saved to the database!" << endl;
        } else {
            cout << " Failed to save admin to database!" << endl;
        }
    } else {
        cout << " Admin not saved to the database." << endl;
    }

}

void search_student() {
    char student_id[MAX_LENGTH];
    cout << "Enter student id to search: ";
    cin >> student_id;
    if (!validateInput(student_id, MAX_LENGTH)) return;
    student *current=student_head;
    while (current != NULL){
        if (strcmp(current->id, student_id)==0){
            cout << "\n=============================================" << endl;
            cout << "          Student Details" << endl;
            cout << "=============================================" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << 
            current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Department: " << current->department << endl;
            cout << "Phone Number: " << current->phone << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            return;
        }
        current = current->next;
    }
    cout << "\nStudent not found in the temporary." << endl;
cout << "Would you like to search from the  this from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if(confirmation == "yes" || confirmation == "y"){
        search_student_in_db(current->id);
    }else{
        cout << " Student search discarded. Not searched in database." << endl;
    }
}

void display_students() {
    cout << "\n=============================================" << endl;
    cout << "             Student List" << endl;
    cout << "=============================================" << endl;
    student *current = student_head;    
    if(current==NULL)
{
    cout << "No students found in the temporary." << endl;
    return;
}
cout <<"students in the temporary storage" << endl;
while(current != NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Department: " << current->department << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    current = current->next;
}
current = student_head;
cout << "would like to display all student from the database.?(yes/no)" << endl;
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_all_students_from_db();
    }else{
        cout << "Students not displayed from the database." << endl;
    }
}

void update_student() {
   char student_id[MAX_LENGTH];
    cout << "\n=============================================" << endl;
    cout << "          Update Student Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to update: ";
    cin >> student_id;
    student *current =  student_head;
   while (current != nullptr){
    if(strcmp(current->name, student_id) == 0){
        cout << "Student found:" << endl;
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Department: " << current->department << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        int choice ;
        cin >>choice ;
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin >> current->name;
                if (!validateInput(current->name, MAX_LENGTH)) return;
                break;
            case 2:
                cout << "Enter new ID: ";
                cin >> current->id;
                if (!validateInput(current->id, 50)) return;
                break;
            case 3:
                cout << "Enter new Gender: " << current->gender;
                if (!validateGender(current->gender)) return;
                break;
            case 4:
                cout << "Enter new Department: ";
                cin >> current->department;
                if (!validateInput(current->department, 50)) return;
                break;
            case 5:
                cout << "Enter new Phone: ";
                cin >> current->phone;
                if (!validatePhoneNumber(current->phone)) return;
                break;
            case 6:
                cout << "Enter new Computer Name: ";
                cin >> current->pcname;
                if (!validateInput(current->pcname, 50)) return;
                break;
            case 7:
            cout << "Enter new Computer Serial Number: ";
                cin >> current->serial;
                if (!validateInput(current->serial, 50)) return;
                break;
                default:
                cout << "\nInvalid choice. Please enter a number between 1 and 7." << endl;
        
    }
    cout << "Student details updated successfully temporary" << endl;
     cout << "Would you like to update this from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        if (update_student_in_db(current->name, current->id, current->gender, current->department, current->phone, current->pcname, current->serial)) {
            cout << " Admin successfully updated in the database!" << endl;
        } else {
            cout << " Failed to update admin in database!" << endl;
        }
    } else {
        cout << " Admin update discarded. Not saved to database." << endl;
    }
    return;
    }
    current = current->next;

   }

}

void delete_student() {
     char student_id[MAX_LENGTH];
cout<<"Enter student id that will be deleted";
cin >>student_id;
   student * current =student_head;
   student *prev = nullptr;
   while(current != NULL){
    if(strcmp(current->id,student_id)==0){
        if(prev == nullptr){
            student_head = current->next;
        }else{
            prev->next = current->next;
        }
        if(current== student_tall){
            student_tall = prev;
        }
        delete current;
        cout << "Student deleted successfully temporary" << endl;
    
   }
    prev = current;
    current = current->next;
}
cout << "Student not fount in temporary" << endl;
delete_student_from_db(student_id);
}
