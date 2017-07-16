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
  ~Hasptr();
private:
  string *ps;
  int i;
};
