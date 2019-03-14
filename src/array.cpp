#include "array.hpp"
#include <cstring>

array::array(int n, int v)
 : arr(nullptr)
 , size(0)
{
    arr = new int[n];
    assert(arr);
    for (int i = 0; i < n; ++i) {
	    arr[i] = v;
    }
    size = n;
}

array::array(const array& p)
 : arr(nullptr)
 , size(0)
{
    size = p.size;
    arr = new int [size];
    for (int j = 0; j < size; j++) {
        arr[j] = p.arr[j];
    }
}

array::~array()
{
	delete [] arr;
	arr = nullptr;
}

void array::print_array() const
{
	for (int i = 0; i < size; i++) {
	    std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}

void array::resize(int i)
{
    if (i < 0) {
        std::cout << "Index is out of range" << std::endl;
	    return;
    }
    int *new_arr = new int[i];
    if (i >= size) {
	    for (int j = size; j < i; j++) {
		    new_arr[j] = 0;
	    }
	    for(int j = 0; j < size; j++) {
		    new_arr[j] = arr[j];
	    }
    }
    else {
	    for(int j = 0; j < i; j++) {
		    new_arr[j] = arr[j];
	    }
    }
    size = i;
    delete [] arr;
    arr = new_arr;

}

int& array::operator[](int i)
{
    return arr[i];
}

int& array::at(int i)
{
	if(i < 0 || i >= size) {
        throw std::out_of_range("Index is out of range");
    }
    return arr[i];
}

array& array::operator=(const array& p)
{
	if (this == &p) {
		return *this;
    } else {
        delete [] arr;
		this->size = p.size;
		this->arr = new int[this->size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = p.arr[i];
		}
		return *this;
	}
}

bool array::operator==(array i)
{
    if (size != i.size) {
        return false;
    } else {
        if (*arr == *(i.arr)) {
		    return true;
        }
        else {
            return false;
        }
   }
}

void array::push_back(int v)
{
    resize(++size);
    arr[size - 1] = v;
}

void array::pop_back()
{
    resize(--size);
}

void array::shift(int p, int c, int d)
{
    if (0 == d) {
        for (int i = size - 1; i > p + 1; --i) {
            arr[i] = arr[i - c];
        }
    } else if (1 == d) {
        for (int i = p; i < size - 1; ++i) {
            arr[i] = arr[i + c];
        }
    }
}

void array::insert(int p, int c)
{
    resize(size + c);
    shift(p, c, 0);
    for (int i = p; i < p + c; ++i) {
        std::cin >> arr[i];
    }
}

void array::erase(int p, int c)
{
   shift(p, c, 1);
   resize(size - c);
}
