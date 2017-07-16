#include "StrBlob.h"

int main()
{
  initializer_list<string> il{"Ankur", "Kumar","Singh","Anshu", "Raghuvanshi"};
  StrBlob sb(il);
  StrBlob sb1;
  StrBlobptr sptr(sb);
  StrBlob s2(sb);
  cout<<sb.front()<<":"<<sb.back()<<endl;
  cout<<sptr.deref()<<endl;
  sb1=sb;
  cout<<sb1.front()<<":"<<sb1.back()<<endl;
  cout<<s2.front()<<":"<<s2.back()<<endl;
  string s ="puja";
  sb.push_back(s);
  cout<<sb1.front()<<":"<<sb1.back()<<endl;
  cout<<s2.front()<<":"<<s2.back()<<endl;
  cout<<sb.front()<<":"<<sb.back()<<endl;
  cout<<sptr.deref()<<endl;
}
