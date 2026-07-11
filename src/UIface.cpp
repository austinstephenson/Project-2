//
// Created by Wstep on 7/10/2026.
//

#include "UIface.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void UIface::runMenu() {
    //Main menu
    cout << endl;
    cout<< "MAIN MENU";
    cout << endl;
    cout << "1. Load patient data from file" << endl;
    cout << "2. Add new patient record" << endl;
    cout << "3. Search patient by ID" << endl;
    cout << "4. Update patient information" << endl;
    cout << "5. Remove patient record" << endl;
    cout << "6. Show top x highest-risk patients" << endl;
    cout << "7. Save data to file" << endl;
    cout << "8. Exit" << endl << endl;

}

void UIface::load() {


    //Call pararmetrized constructor and use CSV file with getline for input

    string filename;
    cout << "Enter CSV filename: ";
    getline(cin, filename);

    if (table.loadCSV(filename))
        cout << "Load successful.\n";
    else
        cout << "Unable to open file.\n";







}

void UIface::addPro() {
}

void UIface::sID() {


    string idcode;
    cout << "Enter Identification Number: ";
    getline(cin, idcode);

    Patient* p= nullptr;
    p= table.search(idcode);
    if (p == nullptr) {
        cout << "Patient not found." << endl;
        return;
    }
    cout<< "Patient found!" << endl;
    p->displayPatient();

}

void UIface::updatePro() {
}

void UIface::removePro() {
}

void UIface::topX() {
}

void UIface::saveToFile() {

    string filename;
    cout << "Enter output filename: ";
    getline(cin, filename);

    if (table.saveCSV(filename))
        cout << "Save successful.\n";
    else
        cout << "Unable to save file.\n";
}

void UIface::exitOP() {
}
