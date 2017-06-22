#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>

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
int main()
{
  lambdacheck(3,5,7);
  return 0;
}
