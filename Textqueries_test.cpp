#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;

int main()
{
  ifstream fin("Sample.txt");
  string str,s;
  vector<string> vec;
  int line_no=0;
  map<string,set<int>> map_set;
  map<string,int> map_match;

  while(getline(fin,str))
  {
    vec.push_back(str);
    istringstream in(str);
    while(in>>s)
    {
      auto itr=map_set.find(s);
      set<int> temp_set;
      if(itr!=map_set.end())
      {
        temp_set=itr->second;
        map_match[s]++;
      }
      temp_set.insert(line_no);
    //  map_set.insert(make_pair(s,temp_set));
      map_set[s]=temp_set;
    }
    line_no++;
  }
  cout<<"Enter the word to find"<<endl;
  cin>>str;
  auto itr=map_set.find(str);
  if(itr!=map_set.end())
  {
    auto temp_set=itr->second;
    auto itr_set=temp_set.begin();
    cout<<"The total number of "<<str<<" is "<<map_match[str]+1<<endl;
    while(itr_set!=temp_set.end())
    {
      cout<<"Line No: "<<*itr_set+1<<" "<<vec[*itr_set]<<endl;
      itr_set++;
    }

  }
}
