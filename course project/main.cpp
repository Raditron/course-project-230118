#include <iostream>
#include "Person.cpp"
#include "HourlyEmployee.cpp"
using namespace std;

int main()
{
    double avg = 0;
    int n;
    cin >> n;
    HourlyEmployee people[n];
    if (n <= 50)
    {
        for (size_t i = 0; i < n; i++)
        {
            string Name, Address;
            string phoneNumber;
            double monthlyClockedHours;
            double hourlySalary;

            cin >> phoneNumber >> Name >> Address >> monthlyClockedHours >> hourlySalary;
            auto person = HourlyEmployee(phoneNumber, Name, Address, monthlyClockedHours, hourlySalary);
            people[i] = person;
            avg += hourlySalary;
            cout << "average salary: " << avg << endl;
            ;
        }
        for (auto &&i : people)
        {
            i.getInfo();
        }
        cout << "average salary: " << avg / n;
    }
    return 0;
}