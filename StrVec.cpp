#include "StrVec.h"

void StrVec::reallocate()
{
  auto new_cap=2*size();
  auto data=alloc.allocate(new_cap);
  auto temp=data;
  for(int i=0;i<size();i++)
  {
    alloc.construct(temp++,std::move(*element++));
  }
  free();
  element=data;
  first_free=temp;
  cap=element+new_cap;
}
void StrVec::push_back(const string &str)
{
  check_n_alloc();
  alloc.construct(first_free++,str);
}

pair<string*, string*> StrVec::alloc_n_copy(string *b, string *e)
{
  auto data=alloc.allocate(e-b);
  return {data, uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
  if(element)
  {
    for(auto p=first_free;p!=element;p--)
    {
      alloc.destroy(p);
    }
    alloc.deallocate(element,cap-element);
  }
}
StrVec::StrVec(const StrVec & sv1)
{
  cout<<"Copy StrVec::StrVec has been called"<<endl;
  auto pt1=alloc_n_copy(sv1.begin(),sv1.end());
  element=pt1.first;
  first_free=cap=pt1.second;
}
StrVec::StrVec(initializer_list<string> il): StrVec()
{
  for(const auto &s:il)
    push_back(s);
}
StrVec& StrVec::operator=(const StrVec & sv1)
{
  cout<<"Copy StrVec::operator= has been called"<<endl;
  auto pt1=alloc_n_copy(sv1.begin(),sv1.end());
  free();
  element=pt1.first;
  first_free=cap=pt1.second;
  return *this;
}
StrVec::StrVec(StrVec &&sv1) noexcept : element(sv1.element), first_free(sv1.first_free), cap(sv1.cap)
{
  cout<<"Move StrVec::StrVec has been called"<<endl;
  sv1.element=sv1.first_free=sv1.cap=nullptr;
}
StrVec& StrVec::operator=(StrVec &&sv1) noexcept
{
  if(this!=&sv1)
  {
    cout<<"Move StrVec::operator= has been called"<<endl;
    free();
    element=sv1.element;
    first_free=sv1.first_free;
    cap=sv1.cap;
    sv1.element=sv1.first_free=sv1.cap=nullptr;
  }
  return *this;
}
bool operator==(const StrVec& sv1, const StrVec& sv2)
{
  return sv1.size()==sv2.size() && equql(sv1.begin(),sv1.end(),sv2.begin());
}
bool operator!=(const StrVec& sv1, const StrVec& sv2)
{
  return !(sv1==sv2);
}
StrVec::~StrVec() {
  free();
}
