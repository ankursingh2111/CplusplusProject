#include<iostream>
#include<string>
#include<deque>
using namespace std;
void deque_element()
{
   deque<string> dq;
   string st1;
   while(cin>>st1)
     dq.push_back(st1);

  auto cstart=dq.cbegin();
  auto cend=dq.cend();
  while(cstart!=cend)
   cout<<*cstart++<<" ";
}
int main()
{
  deque_element();
}
