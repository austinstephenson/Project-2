//
// Created by bosst on 7/11/2026.
#include <ifstream>
#include "Heap.h"
#include <algorithm>

void MaxHeap::siftUp(int i) {
    while (i>0 and heap[parent(i)].getRiskScore()<heap[i].getRiskScore()) {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void MaxHeap::siftDown(int i) {
    int n=heap.size();
    while (true) {

        int largest=i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l].getRiskScore() > heap[largest].getRiskScore()) largest = l;
        if (r < n && heap[r].getRiskScore() > heap[largest].getRiskScore()) largest = r;

        if (largest == i) break;

        swap(heap[i], heap[largest]);
        i = largest;
    }

}

void MaxHeap::insert(Patient& newPatient) {

    newPatient.calcBMI();
    newPatient.calcRiskScore();
    newPatient.calcRiskLevel();

    heap.push_back(newPatient);
    siftUp(heap.size()-1);
}

Patient MaxHeap::peek() {
    return heap[0];
}

Patient MaxHeap::extract() {
    Patient maxPatient=heap[0];

    heap[0]=heap.back();
    if (!heap.empty()) {
        siftDown(0);
    }
    return maxPatient;
}

Patient* MaxHeap::searchId(const string& id) {
    for (auto& p : heap) {
        if (p.getId() == id) return &p;
    }
    return nullptr;
}

bool MaxHeap::removeId(const string& id) {
    int idx = -1;
    for (int i = 0; i < (int)heap.size(); i++) {
        if (heap[i].getId() == id) { idx = i; break; }
    }
    if (idx == -1) return false;

    heap[idx] = heap.back();
    heap.pop_back();

    if (idx < (int)heap.size()) {
        siftUp(idx);
        siftDown(idx);
    }
    return true;
}

bool MaxHeap::loadCSV(const string &filename) {
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
