#include "StrVec.h"

void print(const StrVec &sv) {
  cout << "<" << &sv << "> size: " << sv.size()
            << " capacity: " << sv.capacity() << " contents:";
  for (const auto &s : sv)
    cout << " <" << s << ">";
  cout <<endl;
}

int main() {
  StrVec sv;
  print(sv);

  sv.push_back("s1"); print(sv);
  sv.push_back("s2"); print(sv);
  sv.push_back("s3"); print(sv);
  sv.push_back("s4"); print(sv);
  sv.push_back("s5"); print(sv);
  StrVec sv1=sv;
  StrVec sv2(sv);
  StrVec sv3(std::move(sv2));
  StrVec sv4=std::move(sv);
}
