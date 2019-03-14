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

    void shift(int, int, int);
public:
	class Iterator {};

	array() { arr = nullptr; size = 0; }
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

    void insert(int p, int c = 1);
    void erase(int p, int c);

    void push_back(int);
    void pop_back();

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
