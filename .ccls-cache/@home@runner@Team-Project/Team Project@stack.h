/* 
  * Textbook start code 
*/
#include <iostream>
#include "validation.h"

#ifndef STACK_H
#define STACK_H

class Stack
{
public:   
   /** 
      Constructs an empty stack.
   */
   Stack();

   /**
      Adds an element to the top of the stack.
      @param element the element to add
   */
   void push(std::string element);

   /**
      Yields the element on the top of the stack.
      @return the top element
   */
   std::string top() const;

   /**
      Removes the element from the top of the stack.
   */
   void pop();

   /**
      Yields the number of elements in this stack.
      @return the size
   */
   int size() const;
  
private:
   void grow_if_necessary();
   
   std::string* buffer;
   int len;
   int capacity;
};

#endif
