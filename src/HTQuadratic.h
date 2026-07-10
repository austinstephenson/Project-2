#pragma once
#include "Patient.h"

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
    double lf;



public:
    HTQuadratic();



};