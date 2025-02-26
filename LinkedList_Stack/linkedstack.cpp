#include "linkedstack.h"

// constructor
LinkedStack::LinkedStack()
: S(), n(0) { }				

// number of items in the stack
int LinkedStack::size() const
{ return n; }				

// is the stack empty?
bool LinkedStack::empty() const
{ return n == 0; }				

// get the top element
const Elem& LinkedStack::top() const throw(StackEmpty) {		
	if (empty()) throw StackEmpty("Top of empty stack");
	return S.front();
}

// push element onto stack
void LinkedStack::push(const Elem& e) {
	++n;
	S.addFront(e);
}

// pop the stack
void LinkedStack::pop() throw(StackEmpty) {
	if (empty()) throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}