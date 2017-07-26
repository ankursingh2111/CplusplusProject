#include<iostream>
#include<string>

using namespace std;

class Quote
{
public:
  friend ostream & operator<<(ostream & out, const Quote &);
  Quote()=default;
  Quote(const string &s, double pr): bookNo(s), price(pr),total_cost(0.0) {}
  string isbn() const;
  virtual double net_price(size_t);
  virtual void debug() const;
  virtual ~Quote()=default;
private:
  string bookNo;
protected:
  double price=0.0;
  double total_cost=0.0;
};
ostream & operator<<(ostream & out, const Quote &);

class Bulk_Quote: public Quote
{
public:
  Bulk_Quote()=default;
  Bulk_Quote(const string &s, double pr, size_t cnt, double disc): Quote(s,pr), quantity(cnt), discount(disc) {}
  void debug() const override;
  double net_price(size_t n) override;
private:
  size_t quantity=0;
  double discount=0.0;
};
