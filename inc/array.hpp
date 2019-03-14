#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <assert.h>

class Exception
{
public:
    virtual void what() const {};
};

class Out_of_range : Exception
{
    //TODO
};

class array
{
private:
	int* arr;
	int size;
     
public:
	class Iterator {};	

	array() {} 
	array(int n, int v = 0); 

	array(const array& p);
	~array();
	void print_array() const;
    int size_() const { return size; }

	int& operator[](int i);
	const int& operator[](int i) const { return arr[i]; }
    int& at(int i);

	array& operator=(const array& p);
	bool operator==(array i);
	void resize(int i);

    void insert(int p, int v);
    void insert(int p, int v, int c);
    void erase(int p);

    void push_back(int);
    void pop_back();

    void shift(int, int);
};

template<typename It>
void print_array(It b, It e)
{
	for (; b != e; ++b) {
		//cout << *b ...
	}
}

//for (auto it = v.begin(); it != v.end(); ++it);

#endif
