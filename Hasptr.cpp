#include "Hasptr.h"

Hasptr & Hasptr::operator=(const Hasptr &rhs)
{
  auto newps= new string(*rhs.ps);
  delete ps;
  ps=newps;
  i=rhs.i;
  return *this;
}
Hasptr::~Hasptr()
{
  delete ps;
}
