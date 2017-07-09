#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
  ifstream input("Short-form.txt");
  map<string,string> map_item;
  vector<string> vec_string;
  string str;
  while(getline(input,str))
    vec_string.push_back(str);
  string s;
  for( auto i: vec_string)
  {
    istringstream in(i);
    in>>s;
    getline(in,str);
  //  map_item.insert({s,str.subtsr(1)});
  map_item[s]=str.substr(1);
  }
  ifstream input1("Sample-text.txt");
  while(getline(input1,str))
  {

    istringstream in(str);
    cout<<str<<endl;
    while(in>>s)
    {
      auto itr=map_item.find(s);
      if(itr!=map_item.end())
        s=itr->second;
      cout<<s<<" ";
    }
    cout<<endl;
  }


}
