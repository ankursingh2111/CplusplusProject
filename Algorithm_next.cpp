#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<forward_list>
#include<fstream>
#include<iterator>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
  return s1.size()<s2.size();
}
void Algotest()
{
  vector<int> v1(4,1);
  fill(v1.begin(), v1.end(), 7);
  fill_n(v1.begin(),2,10);
  for(auto ele : v1)
    cout<<ele<<" ";
  cout<<endl;
  vector<string> vstr{"fox","jumps","over","over","quick","red","red","slow","the","the","turtle"};
  sort(vstr.begin(),vstr.end());
  auto itr=unique(vstr.begin(),vstr.end());
  /*while(itr!=vstr.end())
  {
    cout<<*itr<<" ";
    itr++;
  }*/
  cout<<endl;
  vstr.erase(itr,vstr.end());
  for(auto ele: vstr)
    cout<<ele<<" ";

  cout<<endl;
  stable_sort(vstr.begin(), vstr.end(), isShorter);
  for(auto ele: vstr)
    cout<<ele<<" ";
}
void lambdacheck(int s, int s3, int s4)
{
  auto sumcheck=[s] (int s2) { return s+s2;};
  cout<<endl<<sumcheck(s4);
}
void Algochecks()
{
  vector<int> v1{1,-2,-3,4,5,6,-7};
  transform(v1.begin(), v1.end(), v1.begin(), [] (int i) { return i>0?i:-i;});
 
  for(auto ele: v1)
  {
    cout<<ele<<" ";
  }
}
void inserter_test()
{
  vector<int> v1{1,2,3,4,5,6,7,8,9};
  list<int>l1;
  vector<int>v2;
  forward_list<int>fl1;
 
  copy(v1.cbegin(), v1.cend(), back_inserter(v2));
  copy(v1.cbegin(), v1.cend(), front_inserter(fl1));
  copy(v1.cbegin(), v1.cend(), inserter(l1,l1.begin()));

  for(auto ele:v2)
   cout<<ele<<" ";
  
  cout<<endl;

  for(auto ele:fl1)
   cout<<ele<<" ";

  cout<<endl;

 for(auto ele:l1)
   cout<<ele<<" ";

  cout<<endl;
}
void readFile()
{
  ifstream in("Screen.cpp");
  istream_iterator<string> input(in), end;
  vector<string>v1(input,end);
  ostream_iterator<string> out(cout, " ");

  copy(v1.cbegin(),v1.cend(),out);
  cout<<endl;
  
  copy(v1.crbegin(),v1.crend(),out);
  cout<<endl;
//  for(auto ele: v1)
//  cout<<ele<< " ";
  
}
void reversecopyvector()
{
  vector<int> v1{0,1,2,3,4,5,6,7,8,9};
  list<int> li(v1.cbegin()+2,v1.cend()-3);

  for(auto ele: li)
   cout<<ele<<" ";
}
int main()
{
//  lambdacheck(3,5,7);
  cout<<endl;
 // Algochecks();
  cout<<endl;
//  inserter_test();
//  readFile();
  reversecopyvector();
  return 0;
}
