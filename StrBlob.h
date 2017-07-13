#include<iostream>
#include<vector>
#include<string>
#include<memory>

using namespace std;
class StrBlobptr;
class StrBlob
{
public:
  friend class StrBlobptr;
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
  StrBlobptr * begin()
  {
    return StrBlobptr(*this);
  }
  StrBlobptr * end()
  {
    auto ret=StrBlobptr(*this, data->size());
    return ret;
  }
private:
  shared_ptr<vector<string>> data;
  void check_ptr(size_t sz, string msg) const;
};

class StrBlobptr
{
public:
  StrBlobptr(): curr(0);
  StrBlobptr(StrBlob &Sblob, size_t sz=0): wptr(Sblob.data), curr(sz) {}
  string & deref () const;
  StrBlobptr & incr();
private:
  shared_ptr<vector<string>> check_ptr(size_t sz, string msg);
  weak_ptr<vector<string>> wptr;
  size_t curr;
};
