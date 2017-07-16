#include<iostream>
#include<string>

using namespace std;

class X
{
public:
  X()
  {
    cout<<"Normal constructor called"<<endl;
  }
  X(const X&)
  {
    cout<<"Copy constructor called"<<endl;
  }
  X& operator=(const X&)
  {
    cout<<"Copy Assignment operator called"<<endl;
    return *this;
  }
  ~X()
  {
    cout<<"Destructor called"<<endl;
  }
};

int main()
{
  X x1;
  X x2(x1);
  X x4=x1;
  X x3;
  x3=x1;
  X *x;
  x=new X(x2);
  X *x5(new X(x1));
  X *x6=new X(x3);

  delete x;
  delete x5;
  delete x6;
  return 0;

}
