#include<iostream>
#include<string>
#include<memory>
#include<vector>

using namespace std;

int main()
{
  allocator<string> alloc;
  auto p=alloc.allocate(10);
  auto q=p;
  string s ;
  while(cin>>s && q!=p+10)
    alloc.construct(q++,s);


  for(auto x=p; x!=q;x++)
     cout<<*x<<" ";
  while(q!=p)
    alloc.destroy(--q);
  alloc.deallocate(p,10);

}
