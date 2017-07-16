#include<iostream>
#include<string>
#include<fstream>
#include<memory>
#include<vector>
#include<sstream>
#include<map>
#include<set>
using namespace std;
class QueryResult;

class TextQuery
{
public:
  using line_no=vector<string>::size_type;
  TextQuery(ifstream &);
  QueryResult query(const string &str) const;
private:
  shared_ptr<vector<string>> svec;
  map<string,shared_ptr<set<line_no>>> map_set;
};

class QueryResult
{
public:
  using line_no=vector<string>::size_type;
  friend ostream& print(ostream &, QueryResult &);
  QueryResult(const string &str, shared_ptr<vector<string>> svec, shared_ptr<set<line_no>> set_p):
  search(str), svec_ptr(svec), set_ptr(set_p) {}
  set<line_no>::iterator begin() const
  {
    return set_p->begin();
  }
  set<line_no>::iterator end() const
  {
    return set_p->end();
  }
  shared_ptr<vector<string>> get_file() const
  {
    return svec_ptr;
  }
private:
  string search;
  shared_ptr<vector<string>> svec_ptr;
  shared_ptr<set<line_no>> set_ptr;
};

ostream& print(ostream &, QueryResult &);
