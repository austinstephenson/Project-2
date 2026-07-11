//
// Created by bosst on 7/11/2026.

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