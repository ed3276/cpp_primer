#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class B {
public:
    B();
    B(const B&) = delete;
};
class D : public B {
};

class Quote {
public:
    Quote();
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote();
    virtual void debug() const {
        cout << "Quote: bookNo; price." << endl;
    }
    Quote(const Quote &q);
    Quote &operator=(const Quote &q);
    Quote(Quote &&q);
    Quote &operator=(Quote &&q);
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

Quote::Quote()
{
    cout << "call class[class Quote] @@ Quote() @@" << endl;
}
Quote::Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
{
    cout << "call class[class Quote] @@ Quote(const Quote &q) @@" << endl;
}
Quote &Quote::operator=(const Quote &q)
{
    bookNo = q.bookNo;
    price = q.price;
    cout << "call class[class Quote] @@ operator=(const Quote &q) @@" << endl;
    return *this;
}
Quote::Quote(Quote &&q)
{
    bookNo = std::move(q.bookNo);
    price = std::move(q.price);
    cout << "call class[class Quote] @@ Quote(Quote &&q) @@" << endl;
}
Quote &Quote::operator=(Quote &&q)
{
    bookNo = std::move(q.bookNo);
    price = std::move(q.price);
    cout << "call class[class Quote] @@ operator=(Quote &&q) @@" << endl;
    return *this;
}
Quote::~Quote()
{
    cout << "call class[class Quote] @@ ~Quote() @@" << endl;
}

class Bulk_quote : public Quote {
public:
    Bulk_quote();
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug() const override final {
        cout << "Bulk_quote: min_qty; discount." << endl;
    }
    Bulk_quote(const Bulk_quote &);
    Bulk_quote(Bulk_quote &&);
    Bulk_quote &operator=(const Bulk_quote &);
    Bulk_quote &operator=(Bulk_quote &&);
    ~Bulk_quote();
private:
    std::size_t min_qty;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt > min_qty) {
        return cnt * (1 - discount) * price;
    }
    else
        return cnt * price;
}
Bulk_quote::Bulk_quote()
{
    cout << "call class[class Bulk_quote : public Quote] @@ Bulk_quote() @@" << endl;
}
Bulk_quote::Bulk_quote(const Bulk_quote &bq) : Quote(bq)
{
    min_qty = bq.min_qty;
    discount = bq.discount;
    cout << "call class[class Bulk_quote : public Quote] @@ Bulk_quote(const Bulk_quote &bq) @@" << endl;
}
Bulk_quote::Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq))
{
    min_qty = std::move(bq.min_qty);
    discount = std::move(bq.discount);
    cout << "call class[class Bulk_quote : public Quote] @@ Bulk_quote(Bulk_quote &&bq) @@" << endl;
}
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &bq)
{
    Quote::operator=(bq);
    min_qty = bq.min_qty;
    discount = bq.discount;
    cout << "call class[class Bulk_quote : public Quote] @@ operator=(const Bulk_quote &bq) @@" << endl;
    return *this;
}
Bulk_quote &Bulk_quote::operator=(Bulk_quote &&bq)
{
    Quote::operator=(std::move(bq));
    min_qty = std::move(bq.min_qty);
    discount = std::move(bq.discount);
    cout << "call class[class Bulk_quote : public Quote] @@ operator=(Bulk_quote &&bq) @@" << endl;
    return *this;
}
Bulk_quote::~Bulk_quote()
{
    cout << "call class[class Bulk_quote : public Quote] @@ ~Bulk_quote() @@" << endl;
}
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main()
{
    cout << "Hello world!" << endl;
    //D d;
    //D d2(d);
     //D d3(std::move(d));
     {
         Bulk_quote q, p(q);
         q = p;
         p = std::move(q);
         Bulk_quote k(std::move(p));
     }
     {
         vector<shared_ptr<Quote>> basket;
         basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
         basket.push_back(
                          make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
        cout << basket.back()->isbn() << " " << basket.back()->net_price(15) << endl;
     }
    return 0;
}
