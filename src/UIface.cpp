//
// Created by Wstep on 7/10/2026.
//

#include "UIface.h"

#include <chrono>
#include "Compare.h"

#include "Patient.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using namespace std::chrono;

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

    start =high_resolution_clock::now();

    if (table.loadCSV(filename))
        cout << "Hash Load successful.\n";
    else
        cout << "Hash Load failed.\n";
    executiontime();

    start = high_resolution_clock::now();
    if (maxHeap.loadCSV(filename)) {
        cout << "Heap load successful.\n";
    }
    else
        cout << "Heap load failed.\n";
    executiontime();
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

    cout<<"Hashtable method"<<endl;

    //time for Hash search
    start =high_resolution_clock::now();
    p= table.search(idcode);
    if (p == nullptr) {
        cout << "Patient not found." << endl;
        return;
    }
    executiontime();


    cout << "Heap method" << endl;
    start = high_resolution_clock::now();
    //LOGIC FOR HEAP SEARCH
    maxHeap.searchId(idcode);


    executiontime();
    cout << endl;

    cout<< "Patient found!" << endl <<endl;
    p->displayPatient();

}

void UIface::updatePro() {


    string idcode;
    cout << "Enter Identification Number of Patient to update: ";
    getline(cin, idcode);

    Patient* p= nullptr;
    p= table.search(idcode);
    if (p == nullptr) {
        cout << "Patient not found." << endl;
        return;
    }

    bool curupdate = true;
    while (curupdate == true) {

        string input;

        cout <<"Please select a field to update: " << endl;
        cout << "1: age" << endl;
        cout << "2: height" << endl;
        cout << "3: weight" << endl;
        cout << "4: add a fall" << endl;
        cout << "5: amount of medications" << endl;
        cout << "6: risky medication usage" << endl;
        cout << "7: Tug-time" << endl;
        cout << "8: mobility-score" << endl;
        cout << "9: Finish Updating" << endl;

        getline(cin, input);

        if (input == "1") {
            cout << "Enter Patient's age: "<< endl;
            getline(cin, input);
            p->setAge(stoi(input));

        }
        else if (input == "2") {
            cout << "Enter Patient's height: "<< endl;
            getline(cin, input);
            p->setHeight(stod(input));

        }
        else if (input == "3") {
            cout << "Enter Patient's weight: "<< endl;
            getline(cin, input);
            p->setWeight(stod(input));
        }
        else if (input == "4") {
            p->addFall();
            cout << "Fall added." << endl;

        }
        else if (input == "5") {
            cout << "Enter new amount of medication: "<< endl;
            getline(cin, input);
            p->setMedCount(stoi(input));
        }
        else if (input == "6") {
            cout << "Does patient have history of risky medication use? Y/N";
            getline(cin, input);

            if (input == "Y") {
                p->setRiskyMedUse(1);
            }
            else {
                p->setRiskyMedUse(0);
            }

        }
        else if (input == "7") {
            cout << "Enter new Tug-time: "<< endl;
            getline(cin, input);
            p->setTugTime (stod(input));
        }
        else if (input == "8") {
            cout << "Enter new Mobility Score: "<< endl;
            getline(cin, input);
            p->setMobilityScore(stod(input));
        }
        else if (input == "9") {
            p->calcBMI();
            p->calcRiskScore();
            p->calcRiskLevel();

            cout << "Update Complete!" << endl;
            p->displayPatient();

            curupdate = false;
        }
        else {
            cout << "UNKNOWN COMMAND: TRY AGAIN" << endl;
        }
    }



}

void UIface::removePro() {
    string idcode;
    cout << "Enter ID of profile to remove: ";
    getline(cin, idcode);

    Patient* p = table.search(idcode);

    if (p == nullptr) {
        cout << "Patient not found." << endl;
        return;
    }

    //Hash id removal time
    start =high_resolution_clock::now();

    if (table.remove(idcode)) {
        cout << "Patient removed successfully from Hash." << endl;
    }
    else {
        cout << "Removal failed." << endl;
    }
    executiontime();


    //Heap id removal time
    start =high_resolution_clock::now();
    if (maxHeap.removeId(idcode)) {
        cout << "Patient removed successfully from Heap." << endl;
    }
    else {
        cout << "Removal failed." << endl;
    }
    executiontime();

}

void UIface::topXx() {

    vector<Patient> resHash;
    vector<Patient> resHeap;

    string input;
    cout << "How many patients do you wish to display: " << endl;

    getline(cin, input);
    int x = stoi(input);
    cout << "Hashtable method"<<endl;

    start =high_resolution_clock::now();


    ///
    ///resHash = topX(table, x);

    executiontime();

    cout << "Heap method"<<endl;
    start = high_resolution_clock::now();
    //
//    resHeap = topX(maxHeap, x);
    executiontime();

    for (auto it = resHeap.begin(); it != resHeap.end(); ++it) {
        it->displayPatient();
    }
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

    //NEEDS TO EXIST even though empty
}



void UIface::executiontime() {
    high_resolution_clock::time_point end=
        high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken: "
        << duration.count()
        << " microseconds" <<endl;
};
