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
    double mobilityScore,

    double riskScore,
    string riskLevel);

    // get functions

    int getAge;
    char getSex;
    double getHeight;
    double getWeight;
    int getFalls;
    int getMedCount;
    bool getRiskyMedUse;
    double getTugTime;
    double getMobilityScore;
    double getRiskScore;
    string getRiskLevel;

    //setters

    void setName(string newName);
    void setAge(int newAge);
    void setWeight(double newWeight);
    void addFall();
    void setMedCount(int newMedCount);
    void setRiskyMedUse(bool newRiskyMedUse);
    void setTugTime(double newTugTime);
    void setMobilityScore(double newMobilityScore);
    void setRiskScore(double newRiskScore);
    void setRiskLevel(string newRiskLevel);

    //calc -short for calculations

    double calcBMI() const;

    void calcRiskScore();
    void calcRiskLevel();

    void updateRiskAssesment;

    bool isHighRisk() const;

    //displays
    void displayPatient();


    ~Patient();





};
#ifndef UNTITLED_PATIENT_H
#define UNTITLED_PATIENT_H

#endif //UNTITLED_PATIENT_H