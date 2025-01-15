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
  void add_student();
  void add_staff();
  void add_nonstaff();
  void add_user();
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
  void add_nonstaff(){
    nonstaff *new_nonstaff = new nonstaff;
    cout << "Enter nonstaff's name: ";
    cin.ignore();
    cin.getline(new_nonstaff->name, 20);
    cout << "Enter nonstaff's ID: ";
    cin >> new_nonstaff->id;
    cout << "Enter nonstaff's gender (M/F): ";
    cin >> new_nonstaff->gender;
    cout << "Enter nonstaff phone: " ;
    cin >> new_nonstaff->phone;
    cout << "Enter nonstaff computer name: ";
    cin >> new_nonstaff->pcname;
    cout << "Enter nonstaff computer serial number: ";
    cin >> new_nonstaff->serial;
    cout << "Enter nonstaff computer model: ";
    cin >> new_nonstaff->model;


  };
   void add_staff(){
    staff *new_staff=new staff();
    cout << "Enter staff's name: ";
  cin.ignore();
  cin.getline(new_staff->name, 20);
  cout << "Enter staff's ID: ";
  cin >> new_staff->id;
  cout << "Enter staff's gender (M/F): ";
  cin >> new_staff->gender;
  cout << "Enter staff's role: ";
  cin >> new_staff->role;
  cout << "Enter staff's type of PC (laptop/desktop): ";
  cin >> new_staff->typeofpc;
  cout << "Enter staff's phone number: ";
  cin >> new_staff->phone;
  cout << "Enter staff's computer name: ";
  cin >> new_staff->pcname;
  cout << "Enter staff's computer serial number: ";
  cin >> new_staff->serial;
  cout << "Enter staff's computer model: ";
  cin >> new_staff->model;

  };
void add_user(){

 
  
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