//
// Created by Wstep on 7/10/2026.
//
#include <chrono>

#include "Heap.h"
#include "HTQuadratic.h"

#ifndef PROJECT1_UIFACE_H
#define PROJECT1_UIFACE_H


class UIface {
    private:
    HTQuadratic table;
    MaxHeap maxHeap;

    std::chrono::high_resolution_clock::time_point start;

    public:
    bool running;
    void runMenu();

    //Load
    void load();

    void addPro();
    void sID();
    void updatePro();
    void removePro();
    void topX();
    void saveToFile();
    void exitOP();

    //Helpers
    double executiontime();
};


#endif //PROJECT1_UIFACE_H