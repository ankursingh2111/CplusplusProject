#include "Quote.h"

string Quote::isbn() const
{
  return bookNo;
}
double Quote::net_price(size_t n)
{
  total_cost=n*price;
  return n*price;
}
void Quote::debug() const
{
  cout<<"Book_name: "<<isbn()<<": Price: "<<price<<" total_cost: "<<total_cost<<endl;
}
ostream & operator<<(ostream &out, const Quote& Q1)
{
  out<<Q1.isbn()<<" "<<Q1.total_cost<<endl;
  return out;
}
double Bulk_Quote::net_price(size_t n)
{
  if(n>quantity)
    total_cost=n*price - discount;
  return total_cost;
}
void Bulk_Quote::debug() const
{
  cout<<"Book_name: "<<isbn()<<": Price: "<<price<<" total_cost: "<<total_cost
  <<" min_quantity: "<<quantity<<" Discount: "<<discount<<endl;
}
