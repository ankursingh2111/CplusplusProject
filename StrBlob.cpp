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

shared_ptr<vector<string>> StrBlobptr::check_ptr(size_t sz, string msg)
{
  auto ret= wptr.lock()
  if(!ret)
    throw runtime_error("Undefined StrBlobptr\n");
  if(sz>=ret->size())
    throw out_of_range(msg);
    return ret;
}
string & StrBlobptr::deref() const
{
  auto ret=check_ptr(curr, "No entry in vector");
  return ret->[curr];
}
StrBlobptr & incr()
{
  auto ret=check_ptr(curr, "No entry in vector");
  curr++;
  return *this;
}
