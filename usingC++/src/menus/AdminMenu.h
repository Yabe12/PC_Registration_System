#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <iostream>
#include <limits> 
#include "./DeleteMenu.h"
#include "./AddMenu.h"
#include "./UpdateMenu.h"
#include "./SearchMenu.h"
#include "./displayMenu.h"

using namespace std;
void menu_admin() {
    int choice;
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add User\n";
        cout << "2. Update User\n";
        cout << "3. Search and Display\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                add_user();
                break; 
            case 2: 
               Update();
               break;
            case 3:
               search();
               break;
            case 4: 
               display();
               break;
            case 5: 
               return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

#endif // ADMIN_MENU_H