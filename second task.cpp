#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX_PATIENTS = 100;

struct Patient {
    int patient_ID;         
    string name;           
    int age;               
    string disease;        
    int room_number;        
};

Patient patients[MAX_PATIENTS];

int patient_count = 0;

void load_patients_from_file() {
    
    ifstream file("patients.txt");

    if (!file) {
        cout << "Error opening file for loading!" << endl;
        return;
    }

    patient_count = 0;

    while (file >> patients[patient_count].patient_ID) {
        file.ignore();
        getline(file, patients[patient_count].name);
        file >> patients[patient_count].age;
        file.ignore();
        getline(file, patients[patient_count].disease);
        file >> patients[patient_count].room_number;
        file.ignore();

        patient_count++;

        if (patient_count >= MAX_PATIENTS) {
            cout << "Patient capacity reached. Some patients may not be loaded." << endl;
            break;
        }
    }

    file.close();
    cout << "Patients loaded from file successfully!" << endl;
}

void save_patients_to_file() {

    ofstream file("patients.txt");

    if (!file) {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    for (int i = 0; i < patient_count; i++) {
        file << patients[i].patient_ID << endl;
        file << patients[i].name << endl;
        file << patients[i].age << endl;
        file << patients[i].disease << endl;
        file << patients[i].room_number << endl;
    }

    file.close();
    cout << "Patients saved to file successfully!" << endl;
}

void add_patient() {
    cout << "----------------------------------------\n";
    if (patient_count >= MAX_PATIENTS) {
        cout << "Hospital is full, cannot add more patients." << endl;
        return;
    }

    Patient new_Patient;

    cout << "Enter Patient ID: ";
    cin >> new_Patient.patient_ID;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, new_Patient.name);

    cout << "Enter Age: ";
    cin >> new_Patient.age;

    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, new_Patient.disease);

    cout << "Enter Room Number: ";
    cin >> new_Patient.room_number;

    patients[patient_count++] = new_Patient;
    cout << "----------------------------------------\n";

    cout << "Patient added successfully!" << endl;

  save_patients_to_file();
}

void search_patient_by_ID() {
    int id;
    cout << "----------------------------------------\n";
    cout << "Enter Patient ID: ";
    cin >> id;

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].patient_ID == id) {
            
            cout << "Patient ID: " << patients[i].patient_ID << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Room Number: " << patients[i].room_number << endl;
            return;
        }
    }

    cout << "Patient not found!" << endl;
}

void search_patient_by_name() {
    string name;
    cout << "----------------------------------------\n";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].name == name) {
          
            cout << "Patient ID: " << patients[i].patient_ID << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Room Number: " << patients[i].room_number << endl;
            return;
        }
    }

    cout << "Patient not found!" << endl;
}

void display_all_patients() {
    cout << "----------------------------------------\n";
    
    if (patient_count == 0) {
        cout << "No patients admitted." << endl;
        return;
    }

    for (int i = 0; i < patient_count; i++) {
        cout << "Patient ID: " << patients[i].patient_ID << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
        cout << "Room Number: " << patients[i].room_number << endl;
        cout << "----------------------------------------\n";
        
    }
}

void display_menu() {
    cout << "----------------------------------------\n";
    cout << "****************************************\n";
    cout << "***Hospital Patient Management System***" << endl;
    cout << "****************************************\n";
    cout << "1. Add New Patient" << endl;
    cout << "2. Search Patient by ID" << endl;
    cout << "3. Search Patient by Name" << endl;
    cout << "4. Display All Patients" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    load_patients_from_file();

    int choice;

    while (true) {
        display_menu(); 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                search_patient_by_ID();
                break;
            case 3:
                search_patient_by_name();
                break;
            case 4:
                display_all_patients();
                break;
            case 5:
                cout << "********************************\n";
                cout << "***  \"May allah bless you!\"  ***" << endl;
                cout << "********************************\n";
                save_patients_to_file();
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
