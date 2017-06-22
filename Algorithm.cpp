#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
   vector<string> v1={"Ankur", "Kumar", "Singh","Anshu"};
   vector<int> v2 = {1, 2, 4, 5 ,6 ,7, 8,8,7,4,4,4};
   vector<double> v3= {12.2, 14.5, 15.5};

   int sum=accumulate(v2.cbegin(), v2.cend(), 0);
   cout<<"Sum of int is "<<sum<<endl;

   int count1=count(v2.begin(), v2.end(),4);
   cout<<"Count of v2 is "<<count1;
   double sum1=accumulate(v3.cbegin(), v3.cend(), 0.0);
   cout<<"Sum of double is "<<sum1<<endl;

   string name=accumulate(v1.cbegin(), v1.cend(), string(""));
   cout<<"Sum of Name is " <<name<<endl;

  vector<char *> c1= {"Ankur", "Kumar", "Singh", "Anshu"};
  vector<char *> c2= {"Ankur", "Kumar", "Singh"};

  if(equal(c1.cbegin(),c1.cend(),c2.begin()))
    cout<<"Both vectors are equal";
  else
    cout<<"Not equal";
 
  return 0;
}
