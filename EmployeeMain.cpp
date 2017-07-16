#include "Employee.h"

int main()
{
  string str="Ankur";
  Employee E1(str);
  E1.print();
  Employee E2;
  E2.print();
  Employee E3(E1);
  E3.print();
  Employee E4=E2;
  E4.print();
  Employee E5;
  E5.print();
  E5=E1;
  E5.print();
}
