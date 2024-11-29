# course-project-230118
# **Курсова Задача**

---

## **Титулна страница**
**Курсова задача по дисциплина:** Програмиране с обектно-ориентирани езици  
**Тема:** Реализация на програма за управление на служители с почасово заплащане  
**Студент:** Радослав Петров Русев
**Факултетен Номер:** 361224042  
**Ръководител:** Елена Калчева
**Дата:** 29.11.2024

---

## **Текст на заданието**
Да се разработи програма за управление на служители с почасово заплащане. Програмата трябва:  

1. Да дефинира базов клас `Person`, който съдържа основна информация за даден човек: име, телефонен номер и адрес.  
2. Да дефинира клас `HourlyEmployee`, който наследява `Person` и добавя допълнителни полета: месечни работни часове и почасова ставка.  
3. Да предоставя методи за извеждане на информация за служителите, изчисляване на месечните им доходи и пресмятане на средната почасова ставка.  
4. Да позволява въвеждане на информация за до 50 служителя и извеждане на обобщена информация.

---

## **Обобщен блоков алгоритъм**
1. **Начало на програмата**  
2. Въвеждане на броя служители (`n`)  
3. Проверка дали броят служители е ≤ 50:  
   - Ако не, програмата прекратява изпълнение  
4. Създаване на масив от обекти `HourlyEmployee`  
5. За всеки служител:  
   - Въвеждане на данни (име, телефон, адрес, часове, ставка)  
   - Създаване на обект от тип `HourlyEmployee`  
   - Изчисляване на натрупаната средна ставка  
6. Извеждане на информация за всеки служител  
7. Изчисляване и извеждане на средната почасова ставка  
8. Край на програмата  

---

## **Описание на използваните модули**

### **Клас `Person`**
**Елементи и предназначение:**  
- **Поля:**  
  - `string Name` – съхранява името на лицето  
  - `string Address` – съхранява адреса на лицето  
  - `string phoneNumber` – съхранява телефонния номер  
- **Методи:**  
  - Конструктори за инициализация (празен и с параметри)  
  - Сетъри и гетъри за достъп до данните  
  - `virtual void getInfo()` – извежда информация за лицето  

---

### **Клас `HourlyEmployee`**
**Елементи и предназначение:**  
- **Поля:**  
  - `double monthlyClockedHours` – съхранява броя на месечните работни часове  
  - `double hourlySalary` – съхранява почасовата ставка  
- **Методи:**  
  - Конструктори за инициализация (празен и с параметри)  
  - Сетъри и гетъри за достъп до данните  
  - `double monthPayment()` – изчислява месечните доходи на служителя  
  - `void getInfo()` – извежда разширена информация за служителя  

---

## **Общо описание за функциониране на програмата**

### **Вход:**
- Броят на служителите (максимум 50)  
- За всеки служител: телефонен номер, име, адрес, месечни работни часове и почасова ставка  

### **Изход:**
- Информация за всеки служител (име, телефон, адрес, часове, ставка)  
- Средна почасова ставка на всички служители  

---

## **Листинг на изходния код**

### **Файл `main.cpp`**
```cpp
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
        }
        for (auto &&i : people)
        {
            i.getInfo();
        }
        cout << "average salary: " << avg / n;
    }
    return 0;
}
```
### Файл `Person.cpp`
```cpp
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
```
### Файл `HourlyPerson.cpp`
```cpp
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
