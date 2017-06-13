#include<iostream>
#include<string>
#include "Sales_data.h"
using namespace std;


Sales_data & Sales_data::combine(const Sales_data& Sales1)
{
   units_sold+=Sales1.units_sold;
   revenue+=Sales1.revenue;
   return *this;
}
double Sales_data::avg_price() const
{

   double avg=0;
   if(units_sold)
     double avg=revenue/units_sold;
   return avg;
}

Sales_data add(const Sales_data& rhs, const Sales_data& lhs)
{
   Sales_data sum=lhs;
   sum.combine(rhs);
   return sum;
}

ostream & print(ostream& out, const Sales_data& lhs)
{
  out<<lhs.bookNo<<" "<<lhs.units_sold<<" "<<lhs.revenue;
  return out;
}

istream & read(istream &in, Sales_data& lhs)
{
  in>>lhs.bookNo>>lhs.units_sold>>lhs.price;
  lhs.revenue=lhs.units_sold*lhs.price;
  return in;
}
