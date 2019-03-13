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

int& array::resize(int i)
{
    if(i < size) {
        std::cout << "Invalid array size" << std::endl;
    } else {
        int *new_arr = new int[i+1];
        for (int j = 0; j < i; j++) {
            *(new_arr + j) = 0;
        }
        for(int j = 0;j < size; j++) {
            *(new_arr + j)=*(arr + j);
        }
        size = i;
        delete [] arr;
        arr = new_arr;
        return *(arr + i);
    }
    return *(arr + i);
}

int& array::operator[](int i)
{
	if(i < 0 && i >= size) {
		std::cout << "Invalid array size" << std::endl;
	} else {
		return *(arr + i);
    }
    return *(arr + 1);
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
