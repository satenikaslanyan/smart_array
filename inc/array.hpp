#include<iostream>
#include <assert.h>

class array
{
    private:
        int* arr;
        int size;
public:
    array(int n = 10);
    array(const array& p);
    ~array();
    void print_array();
    int& operator [](int i);
    array& operator =(const array& p);
    bool operator ==(array i);
    void resize(int i);
};

