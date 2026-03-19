#include <iostream>
using namespace std;

class Employee
{
public:
  virtual float calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
private:
  float fixedSalary;

public:
  FullTimeEmployee(float salary)
  {
    fixedSalary = salary;
  }

  float calculateSalary()
  {
    return fixedSalary;
  }
};

class PartTimeEmployee : public Employee
{
private:
  float hoursWorked;
  float hourlyRate;

public:
  PartTimeEmployee(float hours, float rate)
  {
    hoursWorked = hours;
    hourlyRate = rate;
  }

  float calculateSalary()
  {
    return hoursWorked * hourlyRate;
  }
};

int main()
{
  FullTimeEmployee emp1(50000);
  PartTimeEmployee emp2(20, 500);

  cout << "Full Time Employee Salary: " << emp1.calculateSalary() << endl;
  cout << "Part Time Employee Salary: " << emp2.calculateSalary() << endl;

  return 0;
}