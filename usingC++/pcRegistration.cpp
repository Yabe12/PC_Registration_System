#include <iostream>
#include <cstring>
using namespace std;
struct student{
  char name[20];
  char id;
  char gender;
  char department;
  int year;
  int phone;
  char pcname;
  char serial;
  char model;
  struct student *next;
  struct student *priv;
};

struct staff{
  char name[20];
  char id;
  char gender;
  char role;
  char typeofpc;
  int phone;
  char pcname;
  char serial;
  char model;
  struct staff *next;
  struct staff *priv;
};

struct nonstaff{
  char name[20];
  char id;
  char gender;
  int phone;
  char pcname;
  char serial;
  char model;
  struct nonstaff *next;
  struct nonstaff *priv;
};
student *student_head = NULL, *student_tall =NULL;
staff *staff_head = NULL, *staff_tall = NULL;
nonstaff *nonstaff_head = NULL, *nonstaff_tall = NULL;

void add_user(){
  void add_student(){
      
  student *new_student = new student;
  cout << "Enter student's name: ";
  cin.ignore();
  cin.getline(new_student->name, 20);
  cout << "Enter student's ID: ";
  cin >> new_student->id;
  cout << "Enter student's gender (M/F): ";
  cin >> new_student->gender;
  cout << "Enter student's department: ";
  cin >> new_student->department;
  cout << "Enter student's year: ";
  cin >> new_student->year;
  cout << "Enter student's phone number: ";
  cin >> new_student->phone;
  cout << "Enter student's computer name: ";
  cin >> new_student->pcname;
  cout << "Enter student's computer serial number: ";
  cin >> new_student->serial;

  };
  void add_staff(){

  };
  void add_nonstaff(){
    
  };
  int choice;
  while(true){
    cout << "Choose a type of user:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      add_student();
      break;
    }else if(choice == 2){
      add_staff();
      break;
    } else if(choice == 3){
      add_staff();
      break;
    }else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}
int main(){
  int choice ;
  while(true){
    cout << "Choose an option:" << endl;
    cout << "1. Add add_user" << endl;
    cout << "2. Search " << endl;
    cout << "3. Delete " << endl;
    cout << "4. Update" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    switch(choice) {
      case 1:
        // add_user();
        break;
      case 2:
        // Search();
        break;
      case 3:
        // add_nonstaff();
        break;
      case 4:
        // Delete();
        break;
      case 13:
      // exit(0);
      default:
      cout << "Invalid choice" << endl;
  
  }
}
return 0;
}