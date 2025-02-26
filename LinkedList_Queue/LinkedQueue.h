#include <string>
using namespace std;
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
//todo : add exceptions


//////////////////////////////////////////////////////////////////////////////////////
//class LinkedQueue
typedef string Elem; // element type
class CNode { // circularly linked list node
private:
	Elem elem; // linked list element value
	CNode* next; // next item in the list
	friend class CircleList; // provide CircleList access
};
class CircleList { // a circularly linked list
public:
	CircleList(); // constructor
	~CircleList(); // destructor
	bool empty() const; // is list empty?
	const Elem& front() const; // element at cursor
	const Elem& back() const; // element following cursor
	void advance(); // advance cursor
	void add(const Elem& e); // add after cursor
	void remove(); // remove node after cursor
private:
	CNode* cursor; // the cursor
};
CircleList::CircleList() // constructor
	: cursor(NULL) { } 
CircleList::~CircleList() // destructor
{
	while (!empty()) remove();
}
bool CircleList::empty() const // is list empty?
{
	return cursor == NULL;
} 
const Elem& CircleList::back() const // element at cursor
{
	return cursor->elem;
} 
const Elem& CircleList::front() const // element following cursor
{
	return cursor->next->elem;
} 
void CircleList::advance() // advance cursor
{
	cursor = cursor->next;
}
void CircleList::add(const Elem& e) { // add after cursor
	CNode* v = new CNode; // create a new node
	v->elem = e;
	if (cursor == NULL) { // list is empty?
		v->next = v; // v points to itself
		cursor = v; // cursor points to v
	}
	else { // list is nonempty?
		v->next = cursor->next; // link in v after cursor
		cursor->next = v;
	}
}
void CircleList::remove() { // remove node after cursor
	CNode* old = cursor->next; // the node being removed
	if (old == cursor) // removing the only node?
		cursor = NULL; // list is now empty
	else
		cursor->next = old->next; // link out the old node
	delete old; // delete the old node
}
//////////////////////////////////////////////////////////////////////////////////////
//class LinkedQueue
typedef string Elem; // queue element type
class LinkedQueue { // queue as doubly linked list
public:
	LinkedQueue(); // constructor
	int size() const; // number of items in the queue
	bool empty() const; // is the queue empty?
	const Elem& front() const throw(QueueEmpty); // the front element
	void enqueue(const Elem& e); // enqueue element at rear
	void dequeue() throw(QueueEmpty); // dequeue element at front
private: // member data
	CircleList C; // circular list of elements
	int n; // number of elements
};
LinkedQueue::LinkedQueue() // constructor
	: C(), n(0) { }
int LinkedQueue::size() const // number of items in the queue
{
	return n;
}
bool LinkedQueue::empty() const // is the queue empty?
{
	return n == 0;
} // get the front element
const Elem& LinkedQueue::front() const throw(QueueEmpty) {
	if (empty())
		throw QueueEmpty("front of empty queue");
	return C.front(); // list front is queue front
}
void LinkedQueue::enqueue(const Elem& e) {
	C.add(e); // insert after cursor
	C.advance(); // . . .and advance
	n++;
} // dequeue element at front
void LinkedQueue::dequeue() throw(QueueEmpty) {
	if (empty())
		throw QueueEmpty("dequeue of empty queue");
	C.remove(); // remove from list front
	n--;
}

#endif

