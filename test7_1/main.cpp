#include <iostream>


struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    double price = 0;
    Sales_data total;
    if(std::cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.units_sold >> price)
        {
            trans.revenue = trans.units_sold * price;
            if(total.bookNo == trans.bookNo)
            {
                total.revenue += trans.revenue;
                total.units_sold += trans.units_sold;
            }
            else
            {
                std::cout << total.bookNo << "   " << total.units_sold << "   " << total.revenue << "   " << total.revenue/total.units_sold << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << "   " << total.units_sold << "   " << total.revenue << "   " << total.revenue/total.units_sold << std::endl;
    }
    else
    {
        std::cout << "No data!" << std::endl;
    }
    return 0;
}
