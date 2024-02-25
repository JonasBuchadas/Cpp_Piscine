// #pragma once
// #ifndef __MUTATED_STACK_TPP
// #define __MUTATED_STACK_TPP

// #include <MutatedStack.hpp>

// template <typename T>
// MutatedStack<T>::MutatedStack() {}

// template <typename T>
// MutatedStack<T>::~MutatedStack() {}

// template <typename T>
// MutatedStack<T>::MutatedStack( const MutatedStack& src ) {}

// template <typename T>
// void MutatedStack<T>::push(const T& n) {
//   this->_data.push(n);
// }

// template <typename T>
// void MutatedStack<T>::pop() {
//   this->_data.pop();
// }

// template <typename T>
// T& MutatedStack<T>::top() {
//   return this->_data.top();
// }

// template <typename T>
// size_t MutatedStack<T>::size() {
//   return this->_data.size();
// }

// template <typename T>
// bool MutatedStack<T>::empty() const {
//   return this->_data.empty();
// }

// template <typename T>
// typename MutatedStack<T>::Iterator MutatedStack<T>::begin() const { return Iterator( *this ); }

// template <typename T>
// typename MutatedStack<T>::Iterator MutatedStack<T>::end() const { return Iterator( MutatedStack() ); }

// #endif
