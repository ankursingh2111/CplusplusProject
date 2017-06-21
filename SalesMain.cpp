#include<iostream>
#include<string>
#include<vector>
#include "Sales_data.h"

bool compareisbn(const Sales_data &rhs, const Sales_data &lhs)
{
  return rhs.isbn()<lhs.isbn();
}
bool charpartition(const Sales_data &rhs)
{
  return rhs.isbn().size()>=5;
}
int main()
{
  Sales_data S1;
  vector<Sales_data> Sales;
  cout<<"Enter the Sales information"<<endl;
  if(read(cin,S1))
  {
    Sales.push_back(S1);
    Sales_data S2;
    while(read(cin,S2))
    {
       Sales.push_back(S2);
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
  cout<<endl;
  sort(Sales.begin(), Sales.end(), [] (const Sales_data &rhs, const Sales_data &lhs) {return rhs.isbn().size()<lhs.isbn().size();});
  stable_sort(Sales.begin(), Sales.end(), [] (const Sales_data &rhs, const Sales_data &lhs) {return rhs.isbn().size()<lhs.isbn().size();});
  //sort(Sales.begin(), Sales.end(),compareisbn);
  for(auto ele : Sales)
   print(cout,ele)<<endl;
  cout<<endl<<endl;
  auto itr=partition(Sales.begin(), Sales.end(), charpartition);
  auto beg=Sales.cbegin();
  while(beg!=itr)
  {
    print(cout,*beg)<<endl;
    beg++;
  }
  return 0;
}
