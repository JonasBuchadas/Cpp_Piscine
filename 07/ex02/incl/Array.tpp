#pragma once

#include <Array.hpp>

template <typename T>
Array<T>::Array() : array(new T[0]), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size(n) {}

template <typename T>
Array<T>::~Array() {
	delete []array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) throw (std::exception) {
	if (i >= size)
		throw Array<T>::OutOfRange();
	return array[i];
}

template <typename T>
Array<T>::Array(const Array<T> &src) : array(src.array), size(src.size) {
	for (unsigned int i = 0; i < size; i++)
		this->array[i] = src.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> &src) const {
	this->size = src.size;
	delete []array;
	// this->array = new T[src.size];
	for (unsigned int i = 0; i < src.size; i++)
		this->array[i] = src.array[i];
}
