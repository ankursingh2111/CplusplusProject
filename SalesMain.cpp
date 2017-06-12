#include<iostream>
#include<string>
#include "Sales_data.h"
using namespace std;

int main()
{
  Sales_data S1;
  cout<<"Enter the Sales information"<<endl;
  if(read(cin,S1))
  {
    Sales_data S2;
    while(read(cin,S2))
    {
       if(S1.isbn()==S2.isbn())
         S1.combine(S2);
       else
       {
         print(cout,S1)<<endl;
         S1=S2;
       }

    }
    print(cout,S1)<<endl;
  }
  return 0;
}
