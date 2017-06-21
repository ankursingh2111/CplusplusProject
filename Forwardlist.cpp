#include<iostream>
#include<string>
#include<forward_list>
using namespace std;

void insertString(forward_list<string> f1, string s1, string s2)
{
  auto it_begin=f1.before_begin();
  auto it_start=f1.begin();
  int count=0;
  cout<<"Function begin\n";
  while(it_start != f1.end())
  {
    if(*it_start==s1)
    {
      f1.insert_after(it_start,s2);
      count=1;
      break;
    }

    it_begin=it_start;
    it_start++;
  }
  if(!count)
   f1.insert_after(it_begin,s2);

  for(auto &fl: f1)
    cout<<fl<<" ";
}

int main()
{
  forward_list<string>f1={"Ankur","Kumar","Singh","Anshu"};
  string s1="Kumar";
  string s2="Raghuvanshi";
  cout<<"Function start"<<endl;

  insertString(f1,s1,s2);

}
