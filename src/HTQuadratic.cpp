//
// Created by bosst on 7/9/2026.
//

#include "HTQuadratic.h"

#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


//Constructor

HTQuadratic::HTQuadratic() {

    size=0;
    capacity=300011;

    table= new Entry[capacity];



}

//LOAD from CSV
bool HTQuadratic::loadCSV(const string &filename) {
    ifstream file(filename);

    if (!file.is_open())
        return false;

    string line;

    // Skip header formatting
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ','))
            fields.push_back(field);

        if (fields.size() != 15)
            continue;

        Patient patient(
            fields[0],                 // id
            fields[1],                 // lastname
            fields[2],                 // firstname
            stoi(fields[3]),           // age
            fields[4][0],              // sex
            stod(fields[5]),           // height
            stod(fields[6]),           // weight
           // stod(fields[7]),           // bmi -> Calculated (not inserted manually)
            stoi(fields[8]),           // falls
            stoi(fields[9]),           // medCount
            stoi(fields[10]),          // riskyMedUse
            stod(fields[11]),          // tug
            stod(fields[12])         // mobility
          //  stod(fields[13]),          // riskScore -> Calculated
          //   fields[14]                 // riskLevel -> Calculated
        );
        patient.calcBMI();
        patient.calcRiskScore();
        patient.calcRiskLevel();


        insert(patient);
    }

    file.close();

    return true;
}

bool HTQuadratic::saveCSV(const string &filename) {

    ofstream file(filename);

    if (!file.is_open())
        return false;

    file << "id,lastname,firstname,age,sex,height,weight,bmi,falls,"
            "medCount,riskyMedUse,tugTime,mobilityScore,riskScore,riskLevel\n";

    for (int i = 0; i < capacity; i++)
    {
        if (table[i].occupied && !table[i].deleted)
        {
            Patient &p = table[i].patient;

            file
                << p.getId() << ','
                << p.getLastname() << ','
                << p.getFirstname() << ','
                << p.getAge() << ','
                << p.getSex() << ','
                << p.getHeight() << ','
                << p.getWeight() << ','
                << p.getBMI() << ','
                << p.getFalls() << ','
                << p.getMedCount() << ','
                << p.getRiskyMedUse() << ','
                << p.getTugTime() << ','
                << p.getMobilityScore() << ','
                << p.getRiskScore() << ','
                << p.getRiskLevel()
                << '\n';
        }
    }

    file.close();

    return true;
}


//HASH Function
int HTQuadratic::hash(const string& key) const {

    unsigned long hash=0;

    for (char c:key) {
        hash=hash*31+c;
    }
    return hash%capacity;

};

//Quadratic probe helper

int HTQuadratic::probeHash(const int index, int i) const {

    return (index+ i*i) % capacity;
}

//Add Patient

bool HTQuadratic::insert(Patient &newPatient) {
    string key=newPatient.getId();

    //generate hash
    int hashcode=hash(key);

    for (int i=0;i<capacity;i++) {

        //check if available
        int index =probeHash(hashcode,i);
        if (!table[index].occupied||table[index].deleted) {

            table[index].id=key;
            table[index].patient=newPatient;


            table[index].occupied=true;
            table[index].deleted=false;

            size++;

            return true;
        }

        if (table[index].id==key and table[index].occupied and!table[index].deleted) {
            return false;
        }


    }
    //full table. might add code to make array larger later.
    return false;

}

//patient search function

Patient* HTQuadratic::search(const string id) {


    int hashcode=hash(id);

    for (int i=0;i<capacity;i++) {

        int index=probeHash(hashcode,i);

        if (!table[index].occupied and !table[index].deleted) {

            return nullptr;
        }

        if (table[index].occupied and table[index].id==id) {
            return &table[index].patient;
        }



    }
    return nullptr;
};


//Remove entry

bool HTQuadratic::remove(string &id) {

    int hashcode=hash(id);
    for (int i=0;i<capacity;i++) {
        int index=probeHash(hashcode,i);


        if (!table[index].occupied and !table[index].deleted) {

               return false;
            }

        if (table[index].id==id and !table[index].deleted and table[index].occupied) {
            table[index].occupied=false;
            table[index].deleted=true;
            size--;

            return true;
        }
    }
    cout<<"Not found"<<endl;
    return false;
};


//-------------sorting--------

//populate a vector
vector<Patient> HTQuadratic::getPatients() const {
    vector<Patient> result;

    for (int i=0;i<capacity;i++) {
        if (table[i].occupied and !table[i].deleted) {
            result.push_back(table[i].patient);
        }
    }
    return result;
};

//merge sort from sorting study guide

void HTQuadratic::sortPatients(vector<Patient>& patients, int start, int end) {

    if (start<end) {
        int middle=(start+end)/2;
        sortPatients(patients,start,middle);
        sortPatients(patients,middle+1,end);

        merge(patients,start,middle,end);
    }


}

//merge sort helper funtion

void HTQuadratic::merge(vector<Patient>& patients, int start, int middle, int end) {

    vector<Patient> left_copy(patients.begin() + start, patients.begin() + middle + 1);
    vector<Patient> right_copy(patients.begin() + middle + 1, patients.begin() + end + 1);

    int i = 0, j = 0, k = start;

    // descending by risk score: highest risk first
    while (i < (int)left_copy.size() && j < (int)right_copy.size()) {
        if (left_copy[i].getRiskScore() >= right_copy[j].getRiskScore()) {
            patients[k++] = left_copy[i++];
        } else {
            patients[k++] = right_copy[j++];
        }
    }

    while (i < (int)left_copy.size()) {
        patients[k++] = left_copy[i++];
    }
    while (j < (int)right_copy.size()) {
        patients[k++] = right_copy[j++];
    }
}

//Destructitotiononator

HTQuadratic::~HTQuadratic() {
    delete[] table;

}
