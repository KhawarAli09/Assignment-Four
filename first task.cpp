#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Book {
    int bookID;            
    string title;          
    string author;         
    int quantity;         
};

const string filename = "library_inventory.txt"; 
const int MAX_BOOKS = 100; 


Book inventory[MAX_BOOKS];
int bookCount = 0;

void load_Inventory() {
    ifstream file;
    file.open(filename); 

    if (file.is_open()) {
        bookCount = 0; 
        while (file >> inventory[bookCount].bookID) {
            file.ignore(); 
            getline(file, inventory[bookCount].title); 
            getline(file, inventory[bookCount].author); 
            file >> inventory[bookCount].quantity; 

            bookCount++;

            if (bookCount >= MAX_BOOKS) {
                cout << "Inventory capacity reached. Some books may not be loaded." << endl;
                break;
            }
        }
        file.close(); 
    }
}

void save_Inventory() {
    ofstream file;
    file.open(filename); 

    if (file.is_open()) {
        for (int i = 0; i < bookCount; i++) {
            file << inventory[i].bookID << endl;       
            file << inventory[i].title << endl;       
            file << inventory[i].author << endl;      
            file << inventory[i].quantity << endl;   
        }
        file.close(); 

    }
    else{
        cout<<"Error in file openinng!\n";
    }
}

void add_Book() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Inventory is full. Cannot add more books." << endl;
        return;
    }
    cout << "-----------------------------------\n";
    cout << "Enter Book ID: ";
    cin >> inventory[bookCount].bookID;
    cin.ignore(); 

    cout << "Enter Title: ";
    getline(cin, inventory[bookCount].title); 

    cout << "Enter Author: ";
    getline(cin, inventory[bookCount].author);

    cout << "Enter Quantity: ";
    cin >> inventory[bookCount].quantity; 
    bookCount++;

    cout << "Book added successfully!" << endl;
    cout << "-----------------------------------\n";
}

void search_BookByID() {
    int id; 
    cout << "-----------------------------------\n";
    cout << "Enter Book ID: ";
    cin >> id; 

    for (int i = 0; i < bookCount; i++) {
        if (inventory[i].bookID == id) {
           
            cout << "Book ID: " << inventory[i].bookID << endl;
            cout << "Title: " << inventory[i].title << endl;
            cout << "Author: " << inventory[i].author << endl;
            cout << "Quantity: " << inventory[i].quantity << endl;
            cout << "-----------------------------------\n";
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void search_BookByTitle() {
    string title;
    cout << "-----------------------------------\n";
    cout << "Enter Title: ";

    cin.ignore(); 
    getline(cin, title); 
    for (int i = 0; i < bookCount; i++) {
        if (inventory[i].title == title) {
            cout << "Book ID: " << inventory[i].bookID << endl;
            cout << "Title: " << inventory[i].title << endl;
            cout << "Author: " << inventory[i].author << endl;
            cout << "Quantity: " << inventory[i].quantity << endl;
            cout << "-----------------------------------\n";
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void display_All_Books() {
    cout << "-----------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "Book ID: " << inventory[i].bookID << endl;
        cout << "Title: " << inventory[i].title << endl;
        cout << "Author: " << inventory[i].author << endl;
        cout << "Quantity: " << inventory[i].quantity << endl;
        cout << "-----------------------------------\n";
    }
}

int main() {
    load_Inventory();

    int choice;

    while (true){
        cout << "*******************************\n"; 
        cout << "***Library Management System***" << endl;
        cout << "*******************************\n";
        cout << "1. Add a new book" << endl;
        cout << "2. Search for a book by Book ID" << endl;
        cout << "3. Search for a book by Title" << endl;
        cout << "4. Display all available books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice; 
        switch (choice) {
            case 1:
                add_Book();
                break;
            case 2:
                search_BookByID();
                break;
            case 3:
                search_BookByTitle();
                break;
            case 4:
                display_All_Books();
                break;
           
            case 5:
                cout << "-----------------------------------\n";
                cout << "**************************\n";
                cout << "***Thanks for comming !***" << endl;
                cout << "**************************";
                 save_Inventory(); 
                return 0;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 

   
    return 0; 
}
