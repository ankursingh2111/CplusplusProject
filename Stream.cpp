#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

istream & checkStream(istream & in)
{
  string str;
  while(in>>str)
    cout<<str<<endl;
  in.clear();
  return in;
}
void readFile()
{
  vector<string> v1;
  string str;
  ifstream file("Screen.cpp");
  while(getline(file,str))
      v1.push_back(str);
  for(auto i: v1)
  {
  // cout<<i<<endl;
     istringstream in(i);
     string s;
      while(in>>s)
        cout<<s<<" ";
  }
}
int main()
{
  if(checkStream(cin))
    cout<<"Stream is valid"<<endl;
  else
    cout<<"Stream is not valid\n";

  readFile();
}
