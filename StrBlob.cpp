#include "StrBlob.h"

StrBlob & StrBlob::operator=(const StrBlob &sb1)
{
  data=make_shared<vector<string>>(*sb1.data);
  return *this;
}
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
/*StrBlobptr & StrBlob::begin() const
{
  return StrBlobptr(*this);
}
StrBlobptr & StrBlob::end() const
{
  return StrBlobptr(*this, data->size());
}*/
bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
  return *lhs.data==*rhs.data;
}
bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
  return !(lhs==rhs);
}
shared_ptr<vector<string>> StrBlobptr::check_ptr(size_t sz, string msg)
{
  auto ret= wptr.lock();
  if(!ret)
    throw runtime_error("Undefined StrBlobptr\n");
  if(sz>=ret->size())
    throw out_of_range(msg);
    return ret;
}
string & StrBlobptr::deref()
{
  auto ret=check_ptr(curr, "No entry in vector");
  return (*ret)[curr];
}
StrBlobptr & StrBlobptr::incr()
{
  auto ret=check_ptr(curr, "No entry in vector");
  curr++;
  return *this;
}
bool operator==(const StrBlobptr& lhs, const StrBlobptr& rhs)
{
  return lhs.wptr.lock()==rhs.wptr.lock() && lhs.curr==rhs.curr;
}
bool operator!=(const StrBlobptr& lhs, const StrBlobptr& rhs)
{
  return !(lhs==rhs);
}
