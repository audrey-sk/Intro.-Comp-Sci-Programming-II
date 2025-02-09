/*
 * List.cpp
 * 
 * Class Description: An DHSL list-based implementation of a List data collection class.
 *
 * Modified on: July 2024
 * Author: AL
 */                  

#include <cstddef>   // Needed for nullptr
#include <iostream>
#include "Node.h"
#include "List.h"

using std::cout;
using std::endl;
	
// Default constructor
List::List() { }

// Destructor
List::~List() {
  while ( getElementCount() > 0 )
    removeAtFront();
} 

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
unsigned int List::getElementCount() const {
  return elementCount;
}

// Description: Inserts "newElement" at the back of the List 
//              and returns true if successful, false otherwise.
// Time Efficicency: O(1)    
bool List::append( int newElement ) {

  bool result = true;
  
  Node* newNode = new Node( newElement );  
  if ( newNode != nullptr ) {  
    
    if ( head == nullptr ) // Empty List
      head = newNode;
  
    if ( tail != nullptr ) // Non-empty list
      tail->next = newNode;

    tail = newNode;
      
    elementCount++; // One more element in the list
  }
  else 
    result = false;
  
  return result;
}

// Description: Inserts "newElement" at the front of the List 
//              and returns true if successful, false otherwise.
// Time Efficicency: O(1)
bool List::prepend( int newElement ) {

  bool result = true;
  
  Node* newNode = new Node( newElement );  
  if ( newNode != nullptr ) {  
    
    if ( tail == nullptr ) // Empty List
      tail = newNode;

    if ( head != nullptr ) // Non-empty list
        newNode->next = head;

    head = newNode;
      
    elementCount++; // One more element in the list
  }
  else 
    result = false;
  
  return result;

}

// Description: Removes the element from the front of the List 
//              and returns true if successful, false otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
bool List::removeAtFront( ) {

  bool result = true;
  
  if ( head != nullptr ) {
    Node * tobeRemoved = head;
    head = head->next;
    
    tobeRemoved->next = nullptr;
    delete tobeRemoved;
    tobeRemoved = nullptr;
      
    if ( head == nullptr ) tail = nullptr;
    
    elementCount--; 
  }
  else 
    result = false;
  
  return result;
} 

// Description: Returns via the parameter the element at the front of the List
//              and returns true if successful, false otherwise. 
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getFrontElement( int * frontElement ) const {
  
  // Put your code here!
bool result = true;
if (head != nullptr) {
  *frontElement = head -> data;
  return result;
} else {
result = false;
return result;
} 
}
  
// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const {

  cout << "This List has " << elementCount << " elements: {";
  if ( head != nullptr ) {
    Node * current = head;
    for ( unsigned int i = 1; i <= elementCount; i++ ) {
      cout << " " << current->data;
      current = current->next;
    }
  }
  cout << " }" << endl;
  return;
}
