#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

//virtual base class
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t min_qty;
    double discount;
};

//refactoring
class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double , std::size_t, double);
    double net_price(std::size_t) const override;
    ~Bulk_quote() = default;
};

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double disc) : \
    Disc_quote(book, sales_price, qty, disc)
{
}

double Bulk_quote::net_price(std::size_t n) const{
    if(n >= min_qty)
        return discount * n * price;
    else
        return n * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    cout << "Hello world!" << endl;
    Quote qt("zzz", 35.9);
    Bulk_quote bqt(qt.isbn(), qt.net_price(1), 10, 0.8);
    print_total(std::cout, qt, 10);
    print_total(std::cout, bqt, 10);
    return 0;
}
