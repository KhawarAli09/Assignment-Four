#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX_PATIENTS = 100;

struct Patient {
    int patientID;         
    string name;           
    int age;               
    string disease;        
    int roomNumber;        
};

Patient patients[MAX_PATIENTS];

int patientCount = 0;

void loadPatientsFromFile() {
    
    ifstream file("patients.txt");

    if (!file) {
        cout << "Error opening file for loading!" << endl;
        return;
    }

    patientCount = 0;

    while (file >> patients[patientCount].patientID) {
        file.ignore();
        getline(file, patients[patientCount].name);
        file >> patients[patientCount].age;
        file.ignore();
        getline(file, patients[patientCount].disease);
        file >> patients[patientCount].roomNumber;
        file.ignore();

        patientCount++;

        if (patientCount >= MAX_PATIENTS) {
            cout << "Patient capacity reached. Some patients may not be loaded." << endl;
            break;
        }
    }

    file.close();
    cout << "Patients loaded from file successfully!" << endl;
}

void savePatientsToFile() {

    ofstream file("patients.txt");

    if (!file) {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        file << patients[i].patientID << endl;
        file << patients[i].name << endl;
        file << patients[i].age << endl;
        file << patients[i].disease << endl;
        file << patients[i].roomNumber << endl;
    }

    file.close();
    cout << "Patients saved to file successfully!" << endl;
}

void addPatient() {
    cout << "----------------------------------------\n";
    if (patientCount >= MAX_PATIENTS) {
        cout << "Hospital is full, cannot add more patients." << endl;
        return;
    }

    Patient newPatient;

    cout << "Enter Patient ID: ";
    cin >> newPatient.patientID;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, newPatient.name);

    cout << "Enter Age: ";
    cin >> newPatient.age;

    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, newPatient.disease);

    cout << "Enter Room Number: ";
    cin >> newPatient.roomNumber;

    patients[patientCount++] = newPatient;
    cout << "----------------------------------------\n";

    cout << "Patient added successfully!" << endl;

    savePatientsToFile();
}

void searchPatientByID() {
    int id;
    cout << "----------------------------------------\n";
    cout << "Enter Patient ID: ";
    cin >> id;

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].patientID == id) {
            
            cout << "Patient ID: " << patients[i].patientID << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Room Number: " << patients[i].roomNumber << endl;
            return;
        }
    }

    cout << "Patient not found!" << endl;
}

void searchPatientByName() {
    string name;
    cout << "----------------------------------------\n";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].name == name) {
          
            cout << "Patient ID: " << patients[i].patientID << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Room Number: " << patients[i].roomNumber << endl;
            return;
        }
    }

    cout << "Patient not found!" << endl;
}

void displayAllPatients() {
    cout << "----------------------------------------\n";
    
    if (patientCount == 0) {
        cout << "No patients admitted." << endl;
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        cout << "Patient ID: " << patients[i].patientID << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
        cout << "Room Number: " << patients[i].roomNumber << endl;
        cout << "----------------------------------------\n";
        
    }
}

void displayMenu() {
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
    loadPatientsFromFile();

    int choice;

    while (true) {
        displayMenu(); 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                searchPatientByID();
                break;
            case 3:
                searchPatientByName();
                break;
            case 4:
                displayAllPatients();
                break;
            case 5:
                cout << "********************************\n";
                cout << "***  \"May allah bless you!\"  ***" << endl;
                cout << "********************************\n";
                savePatientsToFile();
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
