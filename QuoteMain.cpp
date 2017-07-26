#include "Quote.h"

int main()
{
  Quote Q1("Ankur",20);
  Q1.net_price(10);
  cout<<Q1;
  Bulk_Quote bq1("Anshu", 25, 5,20);
  Quote *q1=&bq1;
  q1->net_price(17);
  cout<<*q1;
  Quote q2(bq1);
  q2.net_price(22);
  cout<<q2;
  q2.debug();
  q1->debug();
}
