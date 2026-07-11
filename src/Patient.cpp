//
// Created by Wstep on 7/10/2026.
//
#include "Patient.h"
#include <cmath>
#include <string>




//Default Constructor
Patient::Patient()
    : id("0"),
      lastname(""),
      firstname(""),
      age(0),
      sex(' '),
      height(1.0),
      weight(0.0),
      bmi(0.0),
      falls(0),
      medCount(0),
      riskyMedUse(false),
      tugTime(0.0),
      mobilityScore(0.0),
      riskScore(0.0),
      riskLevel("Low")
{
}

//Parameterized constructor
Patient::Patient(std::string id,
                 std::string lastName,
                 std::string firstName,
                 int age,
                 char sex,
                 double height,
                 double weight,
                 int falls,
                 int medCount,
                 bool riskyMedUse,
                 double tugTime,
                 double mobilityScore)
    : id(id),
      lastname(lastName),
      firstname(firstName),
      age(age),
      sex(sex),
      height(height),
      weight(weight),
      bmi(0.0),
      falls(falls),
      medCount(medCount),
      riskyMedUse(riskyMedUse),
      tugTime(tugTime),
      mobilityScore(mobilityScore),

      riskScore(0.0),
      riskLevel("Low")
{
    calcBMI();
    calcRiskScore();
    calcRiskLevel();
}
    // get functions
string Patient::getId() {
    return this->id;
}

int Patient::getAge() {
        return this->age;
    }

string Patient::getLastname() {
    return this->lastname;
}

string Patient::getFirstname() {
    return this->firstname;
}

char Patient::getSex() {
        return this->sex;
    }

    double Patient::getHeight() {
        return this->height;
    }

    double Patient::getWeight() {
        return this->weight;
    }

    double Patient::getBMI() {
        return this->bmi;
    }

    int Patient::getFalls() {
        return this->falls;
    }

    int Patient::getMedCount() {
        return this->medCount;
    }

    bool Patient::getRiskyMedUse() {
        return this->riskyMedUse;
    }

    double Patient::getTugTime() {
        return this->tugTime;
    }

    double Patient::getMobilityScore() {
        return this->mobilityScore;
    }

    double Patient::getRiskScore() {
        return this->riskScore;
    }

    string Patient::getRiskLevel() {
        return this->riskLevel;
    }

    //setters

    void Patient::setLastName(string newName) {
        this->lastname = newName;
    }
    void Patient::setFirstName(string newName) {
        this->firstname = newName;
    }


    void Patient::setAge(int newAge) {
        this->age = newAge;
    }

    void Patient::setHeight(double newHeight) {
        this ->height = newHeight;
    }
    void Patient::setWeight(double newWeight) {
        this->weight = newWeight;
    }

    void Patient::addFall() {
        this->falls++;
    }

    void Patient::setMedCount(int newMedCount) {
        this->medCount = newMedCount;
    }

    void Patient::setRiskyMedUse(bool newRiskyMedUse) {
        this->riskyMedUse = newRiskyMedUse;
    }

    void Patient::setTugTime(double newTugTime) {
        this->tugTime = newTugTime;
    }

    void Patient::setMobilityScore(double newMobilityScore) {
        this->mobilityScore = newMobilityScore;
    }


void Patient::calcRiskScore(){
    double score = 0.0;
    score += falls * 15.0;
    score += medCount * 3.0;
    score += riskyMedUse ? 10.0 : 0.0;
    score += (tugTime > 13.5) ? (tugTime - 13.5) * 5.0 : 0.0;
    score += (100.0 - mobilityScore) * 0.3;
    score += (age > 75) ? (age - 75) * 0.5 : 0.0;
    this->riskScore = score;
}

    void Patient::setRiskLevel(string newRiskLevel) {
    calcRiskLevel();
    return;
    }

    //calc -short for calculations

    void Patient::calcBMI() {
        this->bmi = (this->weight/ pow(this->height,2)) * 703;
    }

    void Patient::calcRiskLevel() {
        if (riskScore >= 70.0) {
            riskLevel = "High";
        }
        else if (riskScore >= 40.0) {
            riskLevel = "Moderate";
        }
        else {
            riskLevel = "Low";
        }
    }

    void Patient::updateProfile() {
    }

    bool Patient::isHighRisk() {

        if (this->riskScore >= 70) {
            cout << "High-risk Patient" << endl;
            return true;
        }
        return false;
    }

    //displays
    void Patient::displayRiskFactors() {
        cout << "Main Risk Factors: ";
    
        bool hasFactor = false;
    
        if (falls > 0) {
            cout << "Previous fall history";
            hasFactor = true;
        }
    
        if (medCount >= 5) {
            if (hasFactor) cout << ", ";
            cout << "High medication count";
            hasFactor = true;
        }
    
        if (riskyMedUse) {
            if (hasFactor) cout << ", ";
            cout << "Risky medication use";
            hasFactor = true;
        }
    
        if (tugTime > 13.5) {
            if (hasFactor) cout << ", ";
            cout << "Slow TUG time";
            hasFactor = true;
        }
    
        if (mobilityScore < 70.0) {
            if (hasFactor) cout << ", ";
            cout << "Low mobility score";
            hasFactor = true;
        }
    
        if (age >= 75) {
            if (hasFactor) cout << ", ";
            cout << "Advanced age";
            hasFactor = true;
        }
    
        if (bmi < 18.5 || bmi >= 30.0) {
            if (hasFactor) cout << ", ";
            cout << "BMI risk factor";
            hasFactor = true;
        }
    
        if (!hasFactor) {
            cout << "No major risk factors flagged";
        }
    
        cout << endl;
    }

    void Patient::displayPatient() {

        this->isHighRisk();
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->lastname<<", " << this->firstname << endl;
        cout << "Age: " << this->age << endl;
        cout << "Sex: " << this->sex << endl;
        cout << "Height: " << this->height << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "BMI: " << this->bmi <<endl;
        cout << "Falls: " << this->falls << endl;
        cout << "MedCount: " << this->medCount << endl;
        cout << "Use of Risky Medication: " << this->riskyMedUse << endl;
        cout << "TugTime: " << this->tugTime << endl;
        cout << "Mobility-Score: " << this->mobilityScore << endl;
        cout << "Risk Score: " << this->riskScore << endl;
        cout << "Risk Level: " << this->riskLevel << endl;
        displayRiskFactors();
    }


    Patient::~Patient() {
    }
