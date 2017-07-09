#include<iostream>
#include<vector>
#include<string>
#include<memory>

using namespace std;

class StrBlob
{
public:
  typedef vector<string>::size_type size_t;
  StrBlob():data(make_shared<vector<string>>()) {}
  StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

  void push_back(string &s)
  {
    data->push_back(s);
  }
  string & front() const;
  string & back() const;
  void pop_back();
private:
  shared_ptr<vector<string>> data;
  void check_ptr(size_t sz, string msg) const;
};
