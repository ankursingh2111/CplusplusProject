#include<iostream>
#include<string>

using namespace std;

class Sales_data
{
  public:
  string bookNo;
  int units_sold=0;
  double revenue=0.0;
  double price=0.0;
  string isbn() const { return bookNo; } 
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
};

ostream & print(ostream& out, const Sales_data& lhs);

istream & read(istream &in, Sales_data& lhs);
