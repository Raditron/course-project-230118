#include <iostream>
using namespace std;
#include "Person.cpp"

class HourlyEmployee : public Person
{
private:
    double monthlyClockedHours;
    double hourlySalary;

public:
    HourlyEmployee() : Person(), monthlyClockedHours(0), hourlySalary(0){};
    HourlyEmployee(string number, string name, string address, double hours, double salary) : Person(number, name, address)
    {
        this->hourlySalary = salary;
        this->monthlyClockedHours = hours;
    }

    double getSalary() { return hourlySalary; }
    void setSalary(double salary) { this->hourlySalary = salary; }

    double getHours() { return monthlyClockedHours; }
    void setHours(double hours) { this->monthlyClockedHours = hours; }

    double monthPayment()
    {
        double monthlyPayment = hourlySalary * monthlyClockedHours;
        return monthlyPayment;
    }

    void getInfo() override
    {
        cout << "Name: " << this->getName() << endl;
        cout << "Number: " << this->getNumber() << endl;
        cout << "Address: " << this->getAddress() << endl;
        cout << "Hours: " << monthlyClockedHours << endl;
        cout << "Salary: " << hourlySalary << endl;
    }

    ~HourlyEmployee();
};

HourlyEmployee::~HourlyEmployee()
{
}
