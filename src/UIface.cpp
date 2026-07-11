//
// Created by Wstep on 7/10/2026.
//

#include "UIface.h"
#include "Patient.h"
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

    //    1/12
    bool unique =false;

    string input;
    string idcode;
    cout << "Enter a Unique Identification Number: " << endl;
    while (unique == false) {
        getline(cin, idcode);


        //check if unique
        Patient* p;
        p= table.search(idcode);
        if (p == nullptr) {
            unique = true;
        }
        else cout << "ID not unique. Please insert a new ID: " << endl;
    }



    //   2/12
    string ln;
    cout << "Enter Last Name: " << endl;
    getline(cin, ln);

    string fn;
    cout << "Enter First Name: " << endl;
    getline(cin, fn);

    cout << "Enter Patient's age: "<< endl;
    getline(cin, input);
    int ag = stoi(input);


    cout << "Enter Sex of Patient: "<< endl;
    getline(cin, input);

    char se= input[0];


    cout << "Enter height of Patient in inches: "<< endl;
    getline(cin, input);
    double he = stod(input);

    cout << "Enter weight of Patient in pounds: "<< endl;
    getline(cin, input);
    double we = stod(input);

    cout << "Enter number of times Patient has had a dangerous fall: "<< endl;
    getline(cin, input);
    int fa = stoi(input);

    cout << "Enter amount of medications Patient is currently taking: "<< endl;
    getline(cin, input);
    int mc = stoi(input);

    string rm;
    bool r;
    cout << "Does the Patient have a history of risky medication use? Y/N " << endl;
    getline(cin, rm);
    if (rm == "Y") {
        r= true;
    }
    else{
        r= false;
    }

    cout << "Enter Patients Tug-Time in seconds: "<< endl;
    getline(cin, input);
    double tt = stod(input);

    cout << "Enter Patients Mobility-Score: "<< endl;
    getline(cin, input);
    double ms = stod(input);

    Patient p(idcode,ln,fn,ag,se,he,we,fa,mc,r,tt,ms);
    p.calcBMI();
    p.calcRiskScore();
    p.calcRiskLevel();

    table.insert(p);
    cout << "Patient inserted!" << endl;
    p.displayPatient();
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

    table.loadCSV(filename);

    if (table.saveCSV(filename))
        cout << "Save successful.\n";
    else
        cout << "Unable to save file.\n";
}

void UIface::exitOP() {
}
