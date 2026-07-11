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

    void Patient::setRiskScore(double newRiskScore) {
        this->riskScore = newRiskScore;
    }

    void Patient::setRiskLevel(string newRiskLevel) {
        calcRiskLevel();
        return;
    }

    //calc -short for calculations

    void Patient::calcBMI() {
        this->bmi = (this->weight/ pow(this->height,2)) * 703;
    }

    void Patient::calcRiskScore() {
    }

    void Patient::calcRiskLevel() {
        if (riskScore >= 100)
            riskLevel = "SEVERE";
        else if (riskScore >= 50)
            riskLevel = "High";

        else if (riskScore >= 25)
            riskLevel = "Moderate";
        else
            riskLevel = "Low";
    }

    void Patient::updateProfile() {
    }

    bool Patient::isHighRisk() {
        if (this->riskScore >= 50) {
            return true;
        }
        return false;
    }

    //displays
    void Patient::displayPatient() {
    }


    Patient::~Patient() {
    }