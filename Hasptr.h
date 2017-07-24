#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Hasptr
{
public:
  Hasptr(string s=string()): ps(new string(s)), i(0) {}
  Hasptr(const Hasptr &h1): ps(new string(*h1.ps)), i(h1.i) {}
  Hasptr & operator=(const Hasptr&);
  Hasptr(Hasptr &&h1) noexcept: ps(h1.ps), i(h1.i)
  {
    h1.ps=nullptr;
  }
  Hasptr & operator=(Hasptr &&h1) noexcept
  {
    if(this!=&h1)
    {
      delete ps;
      ps=h1.ps;
      i=h1.i;
      h1.ps=nullptr;
    }
    return *this;
  }
  ~Hasptr();
private:
  string *ps;
  int i;
};
