#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Screen
{
   friend class Window_mgr;
   public:
   typedef string::size_type size;
   Screen()=default;
   Screen(size hit, size wid, char c): cr(0), ht(hit), wd(wid), content(hit*wid,c) {}
   Screen(size hit, size wid):cr(0), ht(hit), wd(wid), content(hit*wid,' ') {}
   char get() const
   {
       return content[cr];
   }
   inline char get(size ht, size wd) const; 
   Screen & move(size height, size width);
   Screen &set(char); 
   Screen &set(size, size, char);
   Screen & do_display(ostream &out)
   {
      display(out);
      return *this;
   }
   const Screen & do_display(ostream &out) const
   {
      display(out);
      return *this;
   }
   void display(ostream & out) const
   {
     out<<content<<endl;
   }
   private:
   string content;
   size cr,ht,wd;
};
inline Screen &Screen::set(char c)
{
  content[cr] = c; // set the new value at the current cursor location
  return *this;// return this object as an lvalue 
} 
inline Screen &Screen::set(size r, size col, char ch)
{
  content[r*wd + col] = ch;// set specified location to given value
  return *this;// return this object as an lvalue
}

inline Screen& Screen::move(size height, size width)
{
  size row= height * wd;
  cr= row + width;
  return *this;
}

inline char Screen::get(size ht1, size wd1) const
{
  size row=ht1* wd;
  return content[row+wd1];
}

class Window_mgr
{
  public:
  using Screen_index=vector<Screen>::size_type;
  void clear(Screen_index i);
  private: 
  vector<Screen> screens{Screen(24, 80, ' ')} ; 
};
void Window_mgr::clear(Screen_index i)
{
  Screen &sc=screens[i];
  sc.content=string(sc.ht*sc.wd,' ');
}
