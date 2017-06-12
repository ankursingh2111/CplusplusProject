#include<iostream>
#include<string>

using namespace std;

class Person
{

  public:
  string name;
  string address;
  string name_return() const
  { 
     return name;
  }
  string addr_return() const
  { 
     return address;
  }
 
};

ostream & print(ostream& out, const Person& lhs)
{
  out<<lhs.name<<" "<<lhs.address;
  return out;
}

istream & read(istream &in, Person& lhs)
{
  in>>lhs.name>>lhs.address;
  return in;
}

