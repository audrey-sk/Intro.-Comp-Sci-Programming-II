/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *
 * Modified: July 2024
 * Author: AL
 */

#include <cstddef>   // Needed for nullptr
#include "Node.h"

// Method members - Constructors  
Node::Node(): next( nullptr ) {}

Node::Node( int theData ) {
  data = theData;
  next = nullptr;
}

Node::Node( int theData, Node * theNextNode ) {
  data = theData;
  next = theNextNode;
}