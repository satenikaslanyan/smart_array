#include "array.hpp"

array::array(int n)
{
    arr = NULL;
	arr = new int[n];
    assert(arr);
	for (int i = 0; i < n; i++) {
		*(arr + i) = 0;
    }
	size = n;
}

array::array(const array& p)
{
    size = p.size;
    arr = new int [size];
    for (int j = 0; j < size; j++) {
        arr[j] = p.arr[j];
    }
}
array::~array()
{
    if (arr != NULL) {
        delete [] arr;
    }
}

void array::print_array()
{
	for (int i = 0; i < size; i++) {
	    std::cout << *(arr + i) << "  ";
	}
	std::cout << std::endl;
}

void array::resize(int i)
{
    if(i < 0) {
        std::cout << "Index is out of range" << std::endl;
    } else if (i >= size) {
        int *new_arr = new int[i];
        for (int j = size; j < i; j++) {
            *(new_arr + j) = 0;
        }
        for(int j = 0; j < size; j++) {
            *(new_arr + j) = *(arr + j);
        }
        size = i;
        delete [] arr;
        arr = new_arr;
    }
    else {
        int *new_arr = new int[i];
        for(int j = 0; j < i; j++) {
            *(new_arr + j) = *(arr + j);
        }
        size = i;
        delete []arr;
        arr = new_arr;
    }

}

int& array::operator[](int i)
{
	if(i < 0 || i >= size) {
		std::cout << "Index is out of range" << std::endl;
	} else {
		return *(arr + i);
    }
}

array& array::operator =(const array& p)
{
	if (this == &p) {
		return *this;
    } else {
        delete [] arr;
		this->size = p.size;
		this->arr = new int[this->size];
		for (int i = 0; i < size; i++) {
			*(this->arr + i) = *(p.arr + i);
		}
		return *this;
	}
}

bool array::operator ==(array i)
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
