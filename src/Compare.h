//
// Created by bosst on 7/11/2026.
//


#ifndef PROJECT1_COMPARE_H
#define PROJECT1_COMPARE_H
#include "Heap.h"
#include "HTQuadratic.h"

#endif //PROJECT1_COMPARE_H

//Top Helper function

vector<Patient> topX(MaxHeap heap,int x) {

    vector<Patient> result;

    for (int i = 0; i < x and !heap.empty(); i++) {
        heap.extract();

    }
    return result;
}

vector<Patient> topX(HTQuadratic table, int x) {
    vector<Patient> patients=table.getPatients();

    if (!patients.empty()) {
        table.sortPatients(patients,0,patients.size()-1);
    }
        vector<Patient> result;
        for (int i = 0; i < x and i <(int)patients.size(); i++) {
            result.push_back(patients[i]);
        }
        return result;

}
