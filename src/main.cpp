#include "array.hpp"

int main()
{
    array b(8, 4);
    //for (int i = 0; i < 10; ++i) {
    //    b.push_back(i);
    //}
    b.print_array();
    std::cout << "Input 3 values." << std::endl;
    b.insert(3, 3);
    b.print_array();
    b.erase(2, 3);
    b.print_array();
}

