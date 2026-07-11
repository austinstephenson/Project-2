#pragma once
#include "Patient.h"
#include <fstream>

//
// Created by bosst on 7/9/2026.
//
using namespace std;
#ifndef PROJECT1_HTQUADRATIC_H
#define PROJECT1_HTQUADRATIC_H
#include <string>

#endif //PROJECT1_HTQUADRATIC_H

class Entry {
    public:
    string id;
    Patient patient;
    bool occupied;
    bool deleted;

    Entry() {
        occupied = false;
        deleted = false;
    }
};



class HTQuadratic {

    private:
    int size;
    int capacity;
    Entry* table;

    int hash(const string& key) const;
    int probeHash(int index, int i) const;
    void merge(vector<Patient>& patients, int start, int middle, int end);


public:
    HTQuadratic();


//LOAD and Save
    bool loadCSV(const string& filename);
    bool saveCSV(const string& filename);


    ~HTQuadratic();

    Patient* search(string id);

    bool insert(Patient& newPatient);
    bool remove(string& id);

    //sorting functs
    vector<Patient> getPatients() const;
    void sortPatients(vector<Patient>& patients, int start, int end);



};
