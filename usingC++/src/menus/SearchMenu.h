#ifndef SEARCH_MENU_H
#define SEARCH_MENU_H

#include <iostream>
#include "../services/AdminService.h"
#include "../services/StudentService.h"
#include "../services/NonstaffService.h"
#include "../services/StaffService.h"
#include "AdminMenu.h"
#include <cstring>
using namespace std;

// Function to search user information
void search_menu() {
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

#endif