#include "array.hpp"

int main()
{
    array a(6);
    array b(20);
    std::cout << "a array is: ";
    a.print_array();
    a[10] = 6;
    a[2] = a[5];
    std::cout << "a array is: ";
    a.print_array();
    array c = a;
    std::cout << "c array is: ";
    c.print_array();
    if (a[2] == a[5]) {
        std::cout << "true\n";
    } else {
        std::cout<< "false\n";
    }
    if (a == b) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    a.resize(5);
    std::cout << "a array is: ";
    a.print_array();
    b = a;
    std::cout << "b array is: ";
    b.print_array();
    int d = b[5];
    std::cout << "d = " << d << std::endl;
}

