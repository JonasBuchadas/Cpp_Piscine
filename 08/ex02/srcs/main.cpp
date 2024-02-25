#include <iostream>
#include <stack>

#include "MutatedStack.hpp"

// int main() {
//   MutatedStack<int> ms = MutatedStack<int>();

//   std::cout << ms.empty() << std::endl;
//   ms.push(42);
//   std::cout << ms.top() << std::endl;
//   std::cout << ms.empty() << std::endl;
//   std::cout << ms.size() << std::endl;

//   std::stack<int> s;
//   std::cout << s.empty() << std::endl;
//   s.push(42);
//   std::cout << s.top() << std::endl;
//   std::cout << s.empty() << std::endl;
//   std::cout << s.size() << std::endl;
//   // ms.push(1);
//   // ms.push(2);
//   // ms.push(3);

//   // // Iterate over the stack using the iterator
//   // for (MutatedStack::Iterator it = ms.begin(); it != ms.end(); ++it) {
//   //   std::cout << *it << " ";
//   // }

//   return 0;
// }

int main() {
  MutatedStack<int> ms;

  // Push some elements onto the stack
  ms.push( 1 );
  ms.push( 2 );
  ms.push( 3 );

  // Iterate over the stack using the iterator
  for ( MutatedStack<int>::iterator it = ms.begin(); it != ms.end(); ++it ) {
    std::cout << *it << " ";
  }

  return 0;
}
