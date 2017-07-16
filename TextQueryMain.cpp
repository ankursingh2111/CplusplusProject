#include "TextQuery.h"

int main()
{
  ifstream fin("Sample.txt");
  TextQuery tq(fin);
  QueryResult qr=tq.query("ankur");
  print(cout,qr);
}
