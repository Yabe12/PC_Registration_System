#include <iostream>
#include <cstring>

using namespace std;

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    student *next;
    student *prev;
};

struct staff {
    char name[50];
    char id[20];
    char gender;
    char role[50]; //change to job
    char typeofpc[50]; //to be removed
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    staff *next;
    staff *prev;
};

struct nonstaff {
    char name[50];
    char id[20];
    char gender;
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    nonstaff *next;
    nonstaff *prev;
};

// Global linked list heads
student *student_head = nullptr;
staff *staff_head = nullptr;
nonstaff *nonstaff_head = nullptr;

// 🔹 Add User
void add_user(int type) {
    if (type == 1) {  // Student
        student *new_student = new student;
        cout << "Enter student's name: ";
        cin.ignore();
        cin.getline(new_student->name, 50);
        cout << "Enter student's ID: ";
        cin.getline(new_student->id, 20);
        cout << "Enter student's gender (M/F): ";
        cin >> new_student->gender;
        cin.ignore();
        cout << "Enter student's department: ";
        cin.getline(new_student->department, 50);
        cout << "Enter student's year: ";
        cin >> new_student->year;
        cout << "Enter student's phone number: ";
        cin >> new_student->phone;
        cin.ignore();
        cout << "Enter student's computer name: ";
        cin.getline(new_student->pcname, 50);
        cout << "Enter student's computer serial number: ";
        cin.getline(new_student->serial, 50);
        cout << "Enter student's computer model: ";
        cin.getline(new_student->model, 50);

        new_student->next = student_head;
        if (student_head) student_head->prev = new_student;
        student_head = new_student;
    }
    // Similar implementations for staff & nonstaff (Use same pattern)
}

// 🔹 Search User
void search_user(int type) {
    char query[50];
    cout << "Enter search keyword (ID for student, Name for others): ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student search by ID
        student *temp = student_head;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                cout << "Student Found: " << temp->name << " | ID: " << temp->id << endl;
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search by name 

    // Implement similar logic for staff & nonstaff using name
}

// 🔹 Update User
void update_user(int type) {
    char query[50];
    cout << "Enter the ID or Name of the user to update: ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student update by ID
        student *temp = student_head;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                cout << "Enter new name: ";
                cin.getline(temp->name, 50);
                cout << "Update successful!\n";
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search and update by name 

    // Implement similar logic for staff & nonstaff
}

// 🔹 Delete User
void delete_user(int type) {
    char query[50];
    cout << "Enter the ID or Name of the user to delete: ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student delete by ID
        student *temp = student_head, *prev = nullptr;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == student_head) student_head = temp->next;
                delete temp;
                cout << "Student deleted successfully!\n";
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search and delete by name 

    // Implement similar logic for staff & nonstaff
}

// 🔹 Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add User\n";
        cout << "2. Search User\n";
        cout << "3. Update User\n";
        cout << "4. Delete User\n";
        //add display all users menu
        cout << "5. Exit\n";
        cin >> choice;

        int userType;
        if (choice != 5) {
            cout << "Select user type:\n1. Student\n2. Staff\n3. Nonstaff\n";
            cin >> userType;
        }

        switch (choice) {
            case 1: add_user(userType); break;
            case 2: search_user(userType); break;
            case 3: update_user(userType); break;
            case 4: delete_user(userType); break;
            case 5: return 0;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

/*

- First create (just put in the code) SuperAdmin password and username and that SuperAdmin can create other Admins with username and password,
- and those admins can create,update,search but can't delete user(student, staff, non-staff) data, only the super admin can do that,
- and we our system will have only one superAdmin and as much as Admin and user ,
- and the admin or superAdmin have to login (Authenticated) first befor the can use the system
- super admin can do view(by search and all at once),create,update,delete for both user and Admin 
- show the the searched result and let the SuperAdmin to confirm (go forward or search again ) befor he proceed to delete during deletion of user or admin


*/  
















Yeabsira -SE, [1/16/2025 4:27 PM]
#include <iostream>
#include <cstring>
using namespace std;
struct student{
  char name[20];
  char id[10];
  char gender;
  char department[15];
  char year;
  char phone[10];
  char pcname[20];
  char serial[10];
  char model[20];
  struct student *next;
  struct student *priv;
};

struct staff{
  char name[20];
  char id[10];
  char gender;
  char role[20];
  char typeofpc[20];
   char phone[10];
  char pcname[20];
  char serial[10];
  char model[20];
  struct staff *next;
  struct staff *priv;
};

struct nonstaff{
  char name[20];
  char id[10];
  char gender;
  char phone[10];
  char pcname[20];
  char serial[10];
  char model[20];
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

void sort_student(){
if(student_head==NULL)return;
student *current=student_head->next;
while(current!=NULL){
student *key = current;
student *prev = student_head;
while(prev!= key&&strcmp(prev->id,key->id)<0){
  prev=prev->next;
}
if(prev!=key){
  key->priv->next=key->next;
  if(key->next != NULL){
    key->next->priv=key->priv;
  }
  key->next =prev->next;
  if(prev->next != NULL){
    prev->next->priv=key;
  
}
prev->next =key;
key->next = prev;
}
current = current->next;
}
};
void sort_staff(){
  if(staff_head==NULL)return;
  staff *current=staff_head->next;
  while(current != NULL){
    staff *key = current;
    staff *prev = staff_head;
    while(prev!= key&&strcmp(prev->name,key->name)<0){
      prev=prev->next;
    }
    if(prev!=key){
      key->priv->next=key->next;
      if(key->next != NULL){
        key->next->priv=key->priv;
      }
      key->next =prev->next;
      if(prev->next != NULL){
        prev->next->priv=key;
      }
      prev->next =key;
      key->next = prev;
    }
    current = current->next;
  }
  };

void sort_nonstaff(){
  if(nonstaff_head==NULL)return;
  nonstaff *current=nonstaff_head->next;
  while(current != NULL){
    nonstaff *key = current;
    nonstaff *prev = nonstaff_head;
    while(prev!= key&&strcmp(prev->name,key->name)<0){
      prev=prev->next;
    }
    if(prev!=key){
      key->priv->next=key->next;
      if(key->next != NULL){
        key->next->priv=key->priv;
      }
      key->next =prev->next;
      if(prev->next != NULL){
        prev->next->priv=key;
      }
      prev->next =key;
      key->next = prev;
    }
    current = current->next;
  }
}
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
new_student->next =NULL;
  new_student->priv = student_tall;
  if(student_tall != NULL){student_tall->next =new_student;} student_tall=new_student;
  if(student_head == NULL){student_head=student_tall; 
  }
  cout << "the student is  added"<<endl;
  sort_nonstaff();
  cout <<"the member list sorted sucessfully"<<endl;
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

Yeabsira -SE, [1/16/2025 4:27 PM]
cout << "Enter nonstaff computer model: ";
    cin >> new_nonstaff->model;
  new_nonstaff->next =NULL;
  new_nonstaff->priv = nonstaff_tall;
  if(nonstaff_tall != NULL){nonstaff_tall->next =new_nonstaff;} nonstaff_tall=new_nonstaff;
  if(nonstaff_head == NULL){nonstaff_head=nonstaff_tall; 
  }
  cout << "student added"<<endl;
  sort_nonstaff();
  cout <<"the student list sorted sucessfully"<<endl;


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
  cout << "Enter staff's type of PC (personal laptop/office laptop): ";
  cin >> new_staff->typeofpc;
  cout << "Enter staff's phone number: ";
  cin >> new_staff->phone;
  cout << "Enter staff's computer name: ";
  cin >> new_staff->pcname;
  cout << "Enter staff's computer serial number: ";
  cin >> new_staff->serial;
  cout << "Enter staff's computer model: ";
  cin >> new_staff->model;
  new_staff->next =NULL;
  new_staff->priv = staff_tall;
  if(staff_tall != NULL){staff_tall->next =new_staff;} staff_tall=new_staff;
  if(staff_head == NULL){staff_head=staff_tall; 
  }
  cout << "student added"<<endl;
  sort_staff();
  cout <<"the student list sorted sucessfully"<<endl;

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
      add_nonstaff();
      break;
    }else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}

void search_student(){
  char id[10];
  cout << "Enter student's ID to search: ";
  cin >> id;
  student *current = student_head;
  while(current != NULL){
    if(current->id == id){
      cout << "Student found:" << endl;
      cout << "Name: " << current->name << endl;
      cout << "ID: " << current->id << endl;
      cout << "Gender: " << current->gender << endl;
      cout << "Department: " << current->department << endl;
      cout << "Year: " << current->year << endl;
      cout << "Phone: " << current->phone << endl;
      cout << "Computer Name: " << current->pcname << endl;
      cout << "Computer Serial Number: " << current->serial << endl;
      return;
    }
    current = current->next;
  }
  cout << "Student not found." << endl;
}

void search_nonstaff(){
  char name[100];
  cout << "Enter nonstaff's ID to search: ";
  cin >> name;
  nonstaff *current = nonstaff_head;
  while(current != NULL){
    if(current->name == name){
      cout << "Nonstaff found:" << endl;
      cout << "Name: " << current->name << endl;
      cout << "ID: " << current->id << endl;
      cout << "Gender: " << current->gender << endl;
      cout << "Phone: " << current->phone << endl;
      cout << "Computer Name: " << current->pcname << endl;
      cout << "Computer Serial Number: " << current->serial << endl;
      cout << "Computer Model: " << current->model << endl;
      return;
    }
    current = current->next;
  }
  cout << "Nonstaff not found." << endl;
}

Yeabsira -SE, [1/16/2025 4:27 PM]
void search_staff(){
  char name[10];
  cout << "Enter staff's name to search: ";
  cin >> name;
  staff *current = staff_head;
  while(current != NULL){
    if(current->name == name){
      cout << "Staff found:" << endl;
      cout << "Name: " << current->name << endl;
      cout << "ID: " << current->id << endl;
      cout << "Gender: " << current->gender << endl;
      cout << "Role: " << current->role << endl;
      cout << "Type of PC: " << current->typeofpc << endl;
      cout << "Phone: " << current->phone << endl;
      cout << "Computer Name: " << current->pcname << endl;
      cout << "Computer Serial Number: " << current->serial << endl;
      cout << "Computer Model: " << current->model << endl;
      return;
    }
    current = current->next;
  }
}
void search(){
  int choice;
  while(true){
    cout << "Choose a type of user to search and display:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      search_student();
      break;
    } else if(choice == 2){
      search_staff();
      break;
    } else if(choice == 3){
      search_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
void display_student(){
  student *current = student_head;
  cout << "Student List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Department: " << current->department << endl;
    cout << "Year: " << current->year << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    current = current->next;
    cout << endl;
  }
}
void display_nonstaff(){
  nonstaff *current = nonstaff_head;
  cout << "Nonstaff List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    cout << "Computer Model: " << current->model << endl;
    current = current->next;
    cout << endl;
  }
}
void display_staff(){
  staff *current = staff_head;
  cout << "Staff List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Role: " << current->role << endl;
    cout << "Type of PC: " << current->typeofpc << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    cout << "Computer Model: " << current->model << endl;
    current = current->next;
    cout << endl;
  }
}
void display(){
  int choice;
  while(true){
    cout << "Choose a type of user to search and display:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      display_student();
      break;
    } else if(choice == 2){
      display_staff();
      break;
    } else if(choice == 3){
      display_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
void delete_student(){
  char id[10];
  cout << "Enter student's ID to delete: ";
  cin >> id;
  student *current = student_head, *prev = NULL;
  while(current!= NULL && current->id!= id){
    prev = current;
    current = current->next;
  }
  if(current == NULL){
    cout << "Student not found." << endl;
    return;
  }
  if(prev == NULL){
    student_head = current->next;
  } else{

Yeabsira -SE, [1/16/2025 4:27 PM]
prev->next = current->next;
  }
  delete current;
  cout << "Student deleted successfully." << endl;
}
void delete_staff(){
  char name[10];
  cout << "Enter staff's name to delete: ";
  cin >> name;
  staff *current = staff_head, *prev = NULL;
  while(current!= NULL && current->name!= name){
    prev = current;
    current = current->next;
  }
  if(current == NULL){
    cout << "Staff not found." << endl;
    return;
  }
  if(prev == NULL){
    staff_head = current->next;
  } else{
    prev->next = current->next;
  }
  delete current;
  cout << "Staff deleted successfully." << endl;
}
void delete_nonstaff(){
  char name[10];
  cout << "Enter nonstaff's name to delete: ";
  cin >> name;
  nonstaff *current = nonstaff_head, *prev = NULL;
  while(current!= NULL && current->name!= name){
    prev = current;
    current = current->next;
  }
  if(current == NULL){
    cout << "Nonstaff not found." << endl;
    return;
  }
  if(prev == NULL){
    nonstaff_head = current->next;
  } else{
    prev->next = current->next;
  }
  delete current;
  cout << "Nonstaff deleted successfully." << endl;
}
void Delete(){
    int choice;
  while(true){
    cout << "Choose a type of user to delete :" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      display_student();
      break;
    } else if(choice == 2){
      display_staff();
      break;
    } else if(choice == 3){
      display_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}

void Update(){
  int choice;
  while(true){
    cout << "Choose a type of user to update :" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      // update_student();
      break;
    } else if(choice == 2){
      // update_staff();
      break;
    } else if(choice == 3){
      // update_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
};
int main(){
  int choice ;
  while(true){
    cout << "Choose an option:" << endl;
    cout << "1. Add add_user" << endl;
    cout << "2. Search " << endl;
    cout<< "3.display " << endl;
    cout << "4. Delete " << endl;
    cout << "5. Update" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
    switch(choice) {
      case 1:
        add_user();
        break;
      case 2:
        search();
        break;
      case 3:
        display();
        break;
      case 4:
        Delete();
        break;
      case 5:
        // Update();
        break;
      case 6:
      // exit(0);
      default:
      cout << "Invalid choice" << endl;
  
  }
}
return 0;
}