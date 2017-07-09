#include "StrBlob.h"

void StrBlob::check_ptr(size_t sz, string msg) const
{
  if(sz>=data->size())
     throw out_of_range(msg);
}
void StrBlob::pop_back()
{
  check_ptr(0,"back on empty vector");
  data->pop_back();
}
string & StrBlob::front() const
{
  check_ptr(0,"front on empty vector");
  return data->front();
}
string & StrBlob::back() const
{
  check_ptr(0,"back on empty vector");
  return data->back();
}
