/*
 Specification file for the Patient class
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

class TimeHrMn; // Forward Declaration
// Function Prototypes for Overloaded Stream Operators
ostream &operator<<(ostream &, const TimeHrMn &);
istream &operator>>(istream &, TimeHrMn &);

class Patient
{
private:

    string name;
    double height;
    int age;
    int weight;

public:
    // constructors
    Patient();
    Patient(string initName, int initAge, double initHeight, int initWeight);

    // setters
    void setName(string initName);
    void setAge(int initAge);
    void setHeight(double initHeight);
    void setWeight(int initWeight);

    //getters
    string getName() const;
    int getAge() const;
    double getHeight() const;
    int getWeight() const;

    // other functions: declare display and weightStatus
    void display() const;
    string weightStatus() const;

    // other functions: operators >> and <<
    friend istream &operator>>(istream &, Patient &);
    friend ostream &operator<<(ostream &, const Patient &);

    // other function: operator < 
    bool operator<(const Patient &);
};

#endif
