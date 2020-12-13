#include <iostream>
#include "Sales_data.h"

int main()
{
    std::cout << "Hello world!" << std::endl;
    Sales_data total;
    if(read(std::cin, total))
    {
        Sales_data trans;
        while(read(std::cin, trans))
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cout << "No data!" << std::endl;
    }
    return 0;
}
