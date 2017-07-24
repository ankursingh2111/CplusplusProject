#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
friend ostream& operator<<(ostream& out, const Employee &E1);
friend istream& operator>>(istream& in, Employee &E1);
Employee():emp_name(string()),emp_id(++incr) {}
Employee(string &str):emp_name(str), emp_id(++incr)  {}
Employee(const Employee &E1): emp_name(E1.emp_name), emp_id(++incr)  {}
Employee & operator=(const Employee &E1)
{
  emp_name=E1.emp_name;
  emp_id=++incr;
  return *this;
}
void print()
{
  cout<<emp_id<<":"<<emp_name<<endl;
}
private:
  string emp_name;
  int emp_id;
  static int incr;
};

int Employee::incr=0;
