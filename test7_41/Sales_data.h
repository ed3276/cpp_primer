
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, Sales_data &item);
    //friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
    //Sales_data() = default;
    //Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double price) : bookNo(s), units_sold(n), revenue(n*price) {std::cout << "run 3 parameter constructor.\n";}
    Sales_data() : Sales_data("",0,0) {std::cout << "run default parameter constructor.\n";}
    Sales_data(const std::string &s) : Sales_data(s,0,0) {std::cout << "run 1 string parameter constructor.\n";}
    Sales_data(std::istream &is);
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &rhs);

private:
    double avg_price()const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif // SALES_DATA_H
