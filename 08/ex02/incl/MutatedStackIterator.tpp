#pragma once
#ifndef __MUTATED_STACK_ITERATOR_TPP
#define __MUTATED_STACK_ITERATOR_TPP

#include <MutatedStack.hpp>

template <typename T>
MutatedStack<T>::Iterator::Iterator(const MutatedStack& stack) : tempStack(stack._stack) {}

template <typename T>
T& MutatedStack<T>::Iterator::operator*() { return tempStack.top(); }

template <typename T>
typename MutatedStack<T>::Iterator& MutatedStack<T>::Iterator::operator++() {
  tempStack.pop();
  return *this;
}

template <typename T>
bool MutatedStack<T>::Iterator::operator!=(const Iterator& other) const {
  return !(tempStack.empty() && other.tempStack.empty());
}

#endif
