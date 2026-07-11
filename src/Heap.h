//
// Created by bosst on 7/11/2026.
//
#ifndef PROJECT1_HEAP_H
#define PROJECT1_HEAP_H


#pragma once
#include "Patient.h"
using namespace std;

class MaxHeap {

private:
    vector<Patient> heap;

    int parent(int i) const { return (i-1)/2;}
    int left(int i) const { return (2*i)+1; }
    int right(int i) const { return (2*i)+2; }



public:
    void insert(Patient patient);
    Patient peek();
    Patient extract();


    Patient* searchId(const string& id);
    bool removeId(const string& id);

    int size(){ return heap.size(); };
    bool empty(){return heap.empty();};
    
};

#endif //PROJECT1_HEAP_H