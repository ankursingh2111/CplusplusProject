#include<iostream>
#include<vector>
#include<new>
#include<memory>

using namespace std;

vector<int> * allocate_vector()
{
  vector<int> *v1=new vector<int>;
  return v1;
}
void print_vector(vector<int> *v1)
{
  for(auto i: *v1)
    cout<<i<<" ";
}
void read_value()
{
  int num;
  vector<int> *v1=allocate_vector();
  while(cin>>num)
    v1->push_back(num);
  print_vector(v1);
  delete v1;
}
int main()
{
read_value();
}
