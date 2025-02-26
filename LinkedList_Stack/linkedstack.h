#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

typedef string Elem;				// stack element type
class LinkedStack {				// stack as a linked list
public:
	LinkedStack();				// constructor
	int size() const;				// number of items in the stack
	bool empty() const;				// is the stack empty?
	const Elem& top() const throw(StackEmpty);	// the top element
	void push(const Elem& e);  			// push element onto stack
	void pop() throw(StackEmpty);		// pop the stack
private:                                	// member data
	SLinkedList<Elem> S;			// linked list of elements
	int n;					// number of elements
};

#endif