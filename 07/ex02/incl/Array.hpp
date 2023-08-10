#pragma once

#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
private:
	T *array;
	unsigned int size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();
	Array& operator=(Array& src) const;
	T& operator[](unsigned int i) throw (std::exception);
	class OutOfRange : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "index out of range";
		}
	};
};

#include <Array.tpp>
