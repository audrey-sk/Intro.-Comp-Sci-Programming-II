/*
 * List.h
 * 
 * Class Description: An DHSL list-based implementation of a List data collection class. 
 *
 * Modified on: July 2024
 * Author: AL
 */              


#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {

private:
    Node * head = nullptr;           // Pointer to the first node (element) in the List.
    Node * tail = nullptr;           // Pointer to the last node (element) in the List.
    unsigned int elementCount = 0;   // Current number of elements in List.
	
public:
    // Default constructor
    List();

    // Destructor
    ~List();

    // Description: Returns the current number of elements in the List.
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    unsigned int getElementCount() const;

    // Description: Inserts "newElement" at the back of the List 
    //              and returns true if successful, false otherwise.
    // Time Efficicency: O(1)  
    bool append( int newElement );
	
    // Description: Inserts "newElement" at the front of the List 
    //              and returns true if successful, false otherwise.
    // Time Efficicency: O(1)
    bool prepend( int newElement );
    
    // Description: Removes the element from the front of the List 
    //              and returns true if successful, false otherwise. 
    // Precondition: List is not empty.
    // Time Efficicency: O(1)
    bool removeAtFront( );
    
    // Description: Returns via the parameter the element at the front of the List
    //              and returns true if successful, false otherwise. 
    // Precondition: List is not empty.
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    bool getFrontElement( int * frontElement ) const;

    // Description: Prints all elements in the List.
    // Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
    // Postcondition: List unchanged.
    // Time Efficicency: O(n)
    void printList() const;   
};
#endif