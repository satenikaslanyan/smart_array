#include "array.hpp"

int main()
{
    array b;
    for (int i = 0; i < 10; ++i) {
        b.push_back(i);
    }
    b.print_array();
    b.shift(3, 4);
    b.print_array();
}

