#include<iostream>
#include<string>

#include "Screen.h"

int main()
{
/*  Screen myScreen(5,3);
  const Screen blank(5, 3);
  myScreen.set('#').do_display(cout);// calls nonconstversion 
  myScreen.set(1,2,'#').do_display(cout);
  blank.do_display(cout);// callsconstversion*/

  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(cout);
  cout << "\n"; 
  myScreen.display(cout); 
  cout << "\n";
}
