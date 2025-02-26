#ifndef STACK_H
#define STACK_H
#define STACK_H
#include "runtimeexception.h"
template <typename Type>
class Stack
{
	private:
		enum { DEF_CAP = 100 }; 					// default stack capacity
		Type *st; 									// stack: array of integers
		int cap; 									// stack capacity
		int t_index; 								// index of the top of the stack
	public:
		/* Add code to the constructor to handle initialization */
		Stack(int cap_=DEF_CAP):cap(cap_)	 		// constructor
		{
			t_index = -1;
		}

		int size() const 							// number of items in the stack
		{}

		bool empty() const 							// is the stack empty?
		{return t_index<0;}

		const Type& top() const  throw(EmptyStackException) 	// get the top element
		{return st[t_index];}

		void push(Type var)  throw(FullStackException) 	// push element onto stack
		{ st[++t_index] = var; }

		Type pop() throw(EmptyStackException)				// pop the stack
		{ return st[t_index--]; }
};
#endif
