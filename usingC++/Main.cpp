#include <iostream>
#include <string>
using namespace std;

struct PCInfo {
    int id;
    string studentName;
    string pcModel;
    string pcSpecs;
    PCInfo* next;
};

class CircularLinkedList {
private:
    PCInfo* last;

public:
    CircularLinkedList() : last(nullptr) {}

    void addPC(int id, const string& studentName, const string& pcModel, const string& pcSpecs) {
        PCInfo* newPC = new PCInfo{id, studentName, pcModel, pcSpecs, nullptr};
        if (last == nullptr) {
            last = newPC;
            last->next = last;
        } else {
            newPC->next = last->next;
            last->next = newPC;
            last = newPC;
        }
    }

    void displayPCs() {
        if (last == nullptr) {
            cout << "No PCs registered." << endl;
            return;
        }
        PCInfo* temp = last->next;
        do {
            cout << "ID: " << temp->id << ", Student Name: " << temp->studentName
                 << ", PC Model: " << temp->pcModel << ", PC Specs: " << temp->pcSpecs << endl;
            temp = temp->next;
        } while (temp != last->next);
    }

    PCInfo* searchPC(int id) {
        if (last == nullptr) return nullptr;
        PCInfo* temp = last->next;
        do {
            if (temp->id == id) return temp;
            temp = temp->next;
        } while (temp != last->next);
        return nullptr;
    }
};

void adminMenu(CircularLinkedList& list) {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Register PC\n";
        cout << "2. Display All PCs\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string studentName, pcModel, pcSpecs;
                cout << "Enter PC ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Student Name: ";
                getline(cin, studentName);
                cout << "Enter PC Model: ";
                getline(cin, pcModel);
                cout << "Enter PC Specs: ";
                getline(cin, pcSpecs);
                list.addPC(id, studentName, pcModel, pcSpecs);
                break;
            }
            case 2:
                list.displayPCs();
                break;
            case 3:
                cout << "Exiting Admin Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void userMenu(CircularLinkedList& list) {
    int choice;
    do {
        cout << "\nUser Menu:\n";
        cout << "1. Search PC by ID\n";
        cout << "2. Display All PCs\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                cout << "Enter PC ID: ";
                cin >> id;
                PCInfo* pc = list.searchPC(id);
                if (pc) {
                    cout << "ID: " << pc->id << ", Student Name: " << pc->studentName
                         << ", PC Model: " << pc->pcModel << ", PC Specs: " << pc->pcSpecs << endl;
                } else {
                    cout << "PC not found.\n";
                }
                break;
            }
            case 2:
                list.displayPCs();
                break;
            case 3:
                cout << "Exiting User Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    CircularLinkedList pcList;
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adminMenu(pcList);
                break;
            case 2:
                userMenu(pcList);
                break;
            case 3:
                cout << "Exiting Program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}