#include<iostream>
#include<string>
#include<memory>

using namespace std;

class StrVec
{
public:
  friend bool operator==(const StrVec&, const StrVec&);
  friend bool operator!=(const StrVec&, const StrVec&);
  StrVec(): element(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec(initializer_list<string> il);
  StrVec & operator=(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec & operator=(StrVec &&) noexcept;
  ~StrVec();
  string * begin() const
  {
    return element;
  }
  string *end() const
  {
    return first_free;
  }
  size_t size() const
  {
    return first_free - element;
  }
  size_t capacity() const
  {
    return cap - element;
  }
  void push_back(const string &str);
private:
  void check_n_alloc()
  {
    if(size()==capacity())
       reallocate();
  }
  void free();
  void reallocate();
  allocator<string> alloc;
  pair<string*, string*> alloc_n_copy(string *, string *);
  string * element;
  string *first_free;
  string *cap;
};
bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
