  //
// Created by bosst on 7/9/2026.
//
#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;


class Patient {

private:

    string id;
    string lastname;
    string firstname;
    int age;
    char sex;
    double height; //inches
    double weight; //lbs
    double bmi;

    int falls;
    int medCount;
    bool riskyMedUse;

    double tugTime;
    double mobilityScore;

    double riskScore;
    string riskLevel;

    public:
    //constructors

    Patient();

    Patient(

    string id,
    string lastname,
    string firstname,
    int age,
    char sex,
    double height, //inches
    double weight, //lbs

    int falls,
    int medCount,
    bool riskyMedUse,

    double tugTime,
    double mobilityScore);

    // get functions

    string getId();
    string getLastname();
    string getFirstname();
    int getAge();
    char getSex();
    double getHeight();
    double getWeight();
    double getBMI();
    int getFalls();
    int getMedCount();
    bool getRiskyMedUse();
    double getTugTime();
    double getMobilityScore();
    double getRiskScore();
    string getRiskLevel();

    //setters

    void setLastName(string newName);
    void setFirstName(string newName);
    void setAge(int newAge);
    void setHeight(double newHeight);
    void setWeight(double newWeight);
    void addFall();
    void setMedCount(int newMedCount);
    void setRiskyMedUse(bool newRiskyMedUse);
    void setTugTime(double newTugTime);
    void setMobilityScore(double newMobilityScore);
    void setRiskScore(double newRiskScore);
    void setRiskLevel(string newRiskLevel);

    //calc -short for calculations

    void calcBMI();

    void calcRiskScore();
    void calcRiskLevel();

    void updateProfile();

    bool isHighRisk();

    //displays
    void displayPatient();


    ~Patient();





};
#ifndef UNTITLED_PATIENT_H
#define UNTITLED_PATIENT_H

#endif //UNTITLED_PATIENT_H