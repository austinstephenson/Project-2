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