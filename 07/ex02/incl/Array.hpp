#pragma once

#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();
	Array& operator=(Array& src) const;
	T& operator[](unsigned int i) throw (std::exception);

	class OutOfBounds : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "index out of bounds";
		}
	};
};

#include <Array.tpp>
