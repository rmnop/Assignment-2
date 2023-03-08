#include <iostream>
#include <string>


using namespace std;

class Employee {
public:
    Employee(std::string name, int age) : name(name), age(age) {}
    virtual ~Employee() {}

    virtual double calculateWeeklySalary(int hoursWorked) = 0;
    virtual double calculateHealthCareContributions() = 0;
    virtual int calculateVacationDaysEarned() = 0;

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

protected:
    string name;
    int age;
};

class Professional : public Employee {
public:
    Professional(string name, int age, double monthlySalary, int vacationDays) : Employee(name, age), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

    double calculateWeeklySalary(int hoursWorked) override {
        return monthlySalary / 4; // Assume 4 weeks in a month
    }

    double calculateHealthCareContributions() override {
        return monthlySalary * 0.05; // Assume 5% of monthly salary
    }

    int calculateVacationDaysEarned() override {
        return vacationDays / 12; // Assume 12 months in a year
    }

private:
    double monthlySalary;
    int vacationDays;
};

class Nonprofessional : public Employee {
public:
    Nonprofessional(string name, int age, double hourlyRate, int vacationHoursEarnedPerHour) : Employee(name, age), hourlyRate(hourlyRate), vacationHoursEarnedPerHour(vacationHoursEarnedPerHour) {}

    double calculateWeeklySalary(int hoursWorked) override {
        return hoursWorked * hourlyRate;
    }

    double calculateHealthCareContributions() override {
        return 0.0; 
    }

    int calculateVacationDaysEarned() override {
        return vacationHoursEarnedPerHour * 40; // Assume 40 hours worked per week
    }

private:
    double hourlyRate;
    int vacationHoursEarnedPerHour;
};

int main() {
    Professional professional("Samuel Cabrera", 23, 50, 50);
    Nonprofessional nonprofessional("Phil Stan", 32, 15, 2);

    professional.printInfo();
    cout << "Weekly salary: $" << professional.calculateWeeklySalary(0) << endl;
    cout << "Health care contributions: $" << professional.calculateHealthCareContributions() << endl;
    cout << "Vacation days earned: " << professional.calculateVacationDaysEarned() << endl;

    nonprofessional.printInfo();
    cout << "Weekly salary: $" << nonprofessional.calculateWeeklySalary(30) << endl;
    cout << "Health care contributions: $" << nonprofessional.calculateHealthCareContributions() << endl;
    cout << "Vacation days earned: " << nonprofessional.calculateVacationDaysEarned() << endl;

    return 0;
}