#include "RPN.hpp"

#include <cctype>
#include <cstddef>
#include <cstring>
#include <stdexcept>

RPN::RPN( void ) {}

RPN::RPN( const RPN& src ) : _stack( src._stack ) {}

RPN::~RPN( void ) {}

RPN& RPN::operator=( const RPN& src ) {
  if ( this == &src ) {
    return ( *this );
  }
  _stack = src._stack;
  return ( *this );
}

RPNToken RPN::getRPNToken( char c ) {
  switch ( c ) {
    case ' ':
      return SPACE;
    case '+':
      return ADD;
    case '-':
      return SUB;
    case '*':
      return MULT;
    case '/':
      return DIV;
    default:
      if ( std::isdigit( c ) ) {
        return NUM;
      }
  }
  return NONE;
}

void RPN::performOperation( RPNToken operation ) {
  int num1;
  int num2;

  num2 = _stack.top();
  _stack.pop();

  num1 = _stack.top();
  _stack.pop();

  switch ( operation ) {
    case ADD:
      _stack.push( num1 + num2 );
      break;
    case SUB:
      _stack.push( num1 - num2 );
      break;
    case MULT:
      _stack.push( num1 * num2 );
      break;
    case DIV:
      _stack.push( num1 / num2 );
      break;
    default:
      break;
  }
}

void RPN::calculate( std::string& input ) {
  RPNToken t;
  for ( size_t i = 0; i < input.size(); i++ ) {
    t = getRPNToken( input[i] );
    switch ( t ) {
      case SPACE:
        break;

      case NUM:
        _stack.push( input[i] - '0' );
        break;

      case ADD:
        if ( _stack.size() < 2 )
          throw std::runtime_error( "Error: not enough numbers to make operation." );
        performOperation( t );
        break;

      case SUB:
        if ( _stack.size() < 2 )
          throw std::runtime_error( "Error: not enough numbers to make operation." );
        performOperation( t );
        break;

      case MULT:
        if ( _stack.size() < 2 )
          throw std::runtime_error( "Error: not enough numbers to make operation." );
        performOperation( t );
        break;

      case DIV:
        if ( _stack.size() < 2 )
          throw std::runtime_error( "Error: not enough numbers to make operation." );
        performOperation( t );
        break;

      case NONE:
        throw std::runtime_error( "Error: found unknown operator/number." );
        break;
    }
  }

  if ( _stack.size() != 1 )
    throw std::runtime_error( "Error: wrong number of operations given." );

  std::cout << _stack.top() << std::endl;
}
