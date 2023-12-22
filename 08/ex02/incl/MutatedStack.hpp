#pragma once
#ifndef __MUTATED_STACK_HPP
#define __MUTATED_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutatedStack {
 private:
  std::stack<T> _stack;

 public:
  MutatedStack();
  ~MutatedStack();
  void   push(const T& n);
  void   pop();
  T&     top();
  size_t size();
  bool   empty() const;
  class Iterator {
   private:
    std::stack<T> tempStack;

   public:
    Iterator(const MutatedStack& stack);

    T&        operator*();
    Iterator& operator++();
    bool      operator!=(const Iterator& other) const;
  };

  Iterator begin() const;
  Iterator end() const;
};

#include <MutatedStack.tpp>
#include <MutatedStackIterator.tpp>

#endif
