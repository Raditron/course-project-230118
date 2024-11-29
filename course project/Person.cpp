#pragma once
#include <iostream>
using namespace std;

class Person {
private:
    string Name, Address;
    string phoneNumber;

public:
    Person() : phoneNumber(""), Name(""), Address("") {}
    Person(string number, string name, string address) {
        this->phoneNumber = number;
        this->Name = name;
        this->Address = address;
    }
    ~Person();

    string getName() { return Name; }
    void setName(string name) { this->Name = name; }

    string getNumber() { return phoneNumber; }
    void setNumber(double number) { this->phoneNumber = number; }

    string getAddress() { return Address; }
    void setAddress(string address) { this->Address = address; }

    virtual void getInfo() {
        cout << "Name: " << Name << endl;
        cout << "Number: " << phoneNumber << endl;
        cout << "Address: " << Address << endl;
    }
};


Person::~Person() {}