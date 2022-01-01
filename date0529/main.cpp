#include <iostream>

using namespace std;

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
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(double) const;
    void debug() const override final {
        cout << "Bulk_quote: min_qty; discount." << endl;
    }
private:
    std::size_t min_qty;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(double cnt) const
{
    if (cnt > min_qty) {
        return cnt * (1 - discount) * price;
    }
    else
        return cnt * price;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class base {
public:
    string name() { cout << "call class @@ base @@"; return basename; }
    virtual void print(ostream &os) { cout << "call class @@ base @@"; os << basename; }
private:
    string basename;
};

class derived : public base {
public:
    void print(ostream &os) { cout << "call class @@ derived @@"; base::print(os); os << " " << i; }
private:
    int i;
};

class x {
public:
    virtual void tt() = 0;
};


int main()
{
    cout << "Hello world!" << endl;
    Quote q("0-201-82470-1", 50);
    print_total(cout, q, 10);
    Bulk_quote derived1("0-201-82470-1", 50, 5, .19);
    print_total(cout, derived1, 10);
    cout << derived1.net_price(10) << endl;
    Quote *ptr = &q;
    ptr->debug();
    ptr  = &derived1;
    ptr->debug();
    {
        derived d1;
        base *p = &d1;
        p->print(cout);
    }

    cout << endl << endl << endl;
    {
        derived dobj;
        base bobj, *bp1 = &bobj, *bp2 = &dobj, &br1 = bobj, &br2 = dobj;
        bobj.print(cout); cout << endl;
        dobj.print(cout); cout << endl;
        bp1->name(); cout << endl;
        bp2->name(); cout << endl;
        br1.print(cout); cout << endl;
        br2.print(cout); cout << endl;

    }
    {
         //x x1;
    }
    {
        cout << "+++++++++++" << endl;
        Quote q;
    }
    return 0;
}
