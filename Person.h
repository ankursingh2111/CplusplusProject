#include<iostream>
#include<string>

using namespace std;

class Person
{
  friend ostream & print(ostream& out, const Person& lhs);
  friend istream & read(istream &in, Person& lhs);
  friend ostream & operator<<(ostream& out, const Person& lhs);
  friend istream & operator>>(istream &in, Person& lhs);
  public:
  Person()=default;
  Person(string n, string ad):name(n), address(ad) {}
  Person(istream &is)
  {
    read(is, *this);
  }
  string name_return() const
  {
     return name;
  }
  string addr_return() const
  {
     return address;
  }
  private:
  string name;
  string address;
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
ostream & operator<<(ostream& out, const Person& lhs)
{
  out<<lhs.name<<" "<<lhs.address;
  return out;
}

istream & operator>>(istream &in, Person& lhs)
{
  in>>lhs.name>>lhs.address;
  if(!in)
    lhs=Person();
  return in;
}
