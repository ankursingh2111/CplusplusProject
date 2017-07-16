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
  //StrBlob(const StrBlob &sb1): data(make_shared<vector<string>>(*sb1.data) ) {}
  StrBlob(const StrBlob &sb1): data(new vector<string>(*sb1.data) ) {}
  StrBlob & operator=(const StrBlob &);
  void push_back(string &s)
  {
    data->push_back(s);
  }
  string & front() const;
  string & back() const;
  void pop_back();
  StrBlobptr & begin();
  StrBlobptr & end();

private:
  shared_ptr<vector<string>> data;
  void check_ptr(size_t sz, string msg) const;
};

class StrBlobptr
{
public:
  StrBlobptr(): wptr(), curr(0) {}
  StrBlobptr(StrBlob &Sblob, size_t sz=0): wptr(Sblob.data), curr(sz) {}
  string & deref () ;
  StrBlobptr & incr();
private:
  shared_ptr<vector<string>> check_ptr(size_t sz, string msg) ;
  weak_ptr<vector<string>> wptr;
  size_t curr;
};
