//
// Created by bosst on 7/9/2026.
//



#include "HTQuadratic.h"

#include <string>


//Constructor

HTQuadratic::HTQuadratic() {

    size=0;
    capacity=300011;

    table= new Entry[capacity];



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

        if (table[index].id==key) {
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


//Destructitotiononator

HTQuadratic::~HTQuadratic() {
    delete[] table;

}
