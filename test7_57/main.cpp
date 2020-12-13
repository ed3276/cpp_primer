#include <iostream>

//有的时候类需要它的一些成员与类本身直接相关，而不是与类的各个对象保持关联

class Account
{
public:
    Account(const std::string &s = "") : owner(s), amount(0.0) {}
    Account(const std::string &s, double a) : owner(s), amount(a) {}
    Account(const Account&) = default;
    Account& operator=(const Account& a) = default;
    ~Account() = default;
    void calculate() { amount += amount * interestRate; }
    std::string& get_owner() { return owner;}
    double get_amount() {return amount;}
    static double rate() { return interestRate; }
    static void rate(double);
    void print() {std::cout << "name: " << get_owner() << ", rate: " << rate() << ", amount: " << get_amount();}
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};
void Account::rate(double r)
{
    interestRate = r;
}
double Account::initRate()
{
    return 0.002;
}
double Account::interestRate = initRate();

int main()
{
    std::cout << "Hello world!" << std::endl;
    Account a1("zhang");
    a1.calculate();
    Account a2("li", 10000.0);
    a2.calculate();
    a1.print();std::cout << std::endl;
    a2.print();std::cout << std::endl;
    Account::rate(0.03);
    a1.calculate();
    a2.calculate();
    a1.print();std::cout << std::endl;
    a2.print();std::cout << std::endl;
    return 0;
}
