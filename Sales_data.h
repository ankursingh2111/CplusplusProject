#include<iostream>
#include<string>

using namespace std;

class Sales_data
{
  friend ostream & print(ostream& out, const Sales_data& lhs);
  friend istream & read(istream &in, Sales_data& lhs);
  friend Sales_data add(const Sales_data& rhs, const Sales_data& lhs);
  friend ostream & operator<<(ostream& out, const Sales_data& lhs);
  friend istream & operator>>(istream &in, Sales_data& lhs);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);

  public:
  //Sales_data():bookNo(),units_sold(0),price(0.0),revenue(0.0) {}
  //Sales_data(string s):bookNo(s),units_sold(0),price(0.0),revenue(0.0) {}
  Sales_data(string s):Sales_data(s,0,0.0) {}
  Sales_data():Sales_data("",0,0.0) {}
  Sales_data(string s,int ut, double pr):bookNo(s),units_sold(ut),price(pr),revenue(pr*ut) {}
  Sales_data(istream &is): Sales_data()
  {
     read(is, *this);
  }
  string isbn() const { return bookNo; }
  Sales_data & operator+=(const Sales_data&);
  Sales_data& combine(const Sales_data&);
  private:
  string bookNo;
  int units_sold;
  double price;
  double revenue;
  double avg_price() const;
};

ostream & print(ostream& out, const Sales_data& lhs);
Sales_data add(const Sales_data& rhs, const Sales_data& lhs);
istream & read(istream &in, Sales_data& lhs);
ostream & operator<<(ostream& out, const Sales_data& lhs);
istream & operator>>(istream &in, Sales_data& lhs);
Sales_data operator+(const Sales_data &, const Sales_data &);
