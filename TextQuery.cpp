#include "TextQuery.h"

TextQuery::TextQuery(ifstream &fin): svec(new vector<string>)
{
  string str,s;
  int line_count=0;
  while(getline(fin,str))
  {
    svec->push_back(str);
    istringstream in(str);
    while(in>>s)
    {
      auto &line_set=map_set[s];
      if(!line_set)
        line_set.reset(new set<line_no>);
      line_set->insert(line_count);
    }
    line_count++;
  }
}

QueryResult  TextQuery::query(const string &str) const
{
  static shared_ptr<set<line_no>> nodata(new set<line_no>);

  auto line=map_set.find(str);
  if(line==map_set.end())
    return QueryResult(str, svec, nodata);
  else
    return QueryResult(str, svec, line->second);
}

ostream & print(ostream& os, QueryResult &qr)
{
  os<<"the word"<<qr.search<<"has been found"<<(qr.set_ptr)->size()<<endl;

  for(auto &num : *(qr.set_ptr))
    os<<"line no: "<<num+1<<" "<<*(qr.svec_ptr->begin()+num)<<endl;

  return os;
}
