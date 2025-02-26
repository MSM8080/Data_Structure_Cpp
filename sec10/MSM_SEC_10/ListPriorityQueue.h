#ifndef ListPriorityQueue_header
#define ListPriorityQueue_header
#include <iostream>
#include "list"
#include "process.h"
#include "vector2d.h"

using namespace std;

template <typename E, typename C>
class ListPriorityQueue {
	public:
		int size() const; // number of elements
		bool empty() const; // is the queue empty?
		void insert(const E& e); // insert element
		const E& min() const; // minimum element
		void removeMin(); // remove minimum
        void print();
        void printProcess();
        std::list<E> ReturnSortedList();
	private:
		std::list<E> L; // priority queue contents
		C isLess; // less-than comparator
};

template <typename E, typename C>
std::list<E> ListPriorityQueue<E,C>::ReturnSortedList()
{
    return L;
}

template <typename E, typename C> // number of elements
void ListPriorityQueue<E,C>::printProcess()
{
    for (typename std::list<E>::iterator i = L.begin(); i != L.end(); i++)
    {
        Process p = *i;
        p.print();
        cout<<endl;
    }
}
//
//void ListPriorityQueue::printPoint()
//{
//    for (typename std::list<E>::iterator i = L.begin(); i != L.end(); i++)
//    {
//        Point p = *i;
//        cout<<"point: "<<p.x<<", "<<p.y<<endl;
//    }
//}

template <typename E, typename C> // number of elements
void ListPriorityQueue<E,C>::print()
{
    for (typename std::list<E>::iterator i = L.begin(); i != L.end(); i++)
    {
        cout<< *i << ' ';
    }
}

template <typename E, typename C> // number of elements
int ListPriorityQueue<E,C>::size() const
{ return L.size(); }

template <typename E, typename C> // is the queue empty?
bool ListPriorityQueue<E,C>::empty() const
{ return L.empty(); }

template <typename E, typename C> // insert element
void ListPriorityQueue<E,C>::insert(const E& e) {
	typename std::list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && !isLess(e, *p)) ++p; // find larger element
		L.insert(p, e); // insert e before p
}

template <typename E, typename C> // minimum element
const E& ListPriorityQueue<E,C>::min() const
{ return L.front(); } // minimum is at the front

template <typename E, typename C> // remove minimum
void ListPriorityQueue<E,C>::removeMin()
{ L.pop_front(); }
// ----------------------------------------------------------------------------------------------------------------------------
template <typename E>
class AscendingOrder
{
public:
        bool operator()(const E& x, const E& y)
        {
            return (x<y);
        }
};

template <typename E>
class DescendingOrder
{
public:
        bool operator()(const E& x, const E& y)
        {
            return (x>y);
        }
};

template <typename E>
class AscendingOrderProcessTime
{
public:
        bool operator()(const E& x, const E& y)
        {
            return (x.getExecutionTime() < y.getExecutionTime());
        }
};

template <typename E>
class AscendingOrderProcessPrority
{
public:
        bool operator()(const E& x, const E& y)
        {
            return (x.getPriority() < y.getPriority());
        }
};

template <typename E>
class AscendingOrderProcessProrityTime
{
public:
        bool operator()(const E& x, const E& y)
        {
            if(x.getPriority() < y.getPriority())
                return (x.getPriority() < y.getPriority());
            else if(x.getPriority() == y.getPriority())
                return (x.getExecutionTime() < y.getExecutionTime());
        }
};


class dist
{
public:
        bool operator()(const Point& p, const Point& q)
        {
            Point v;
            Vector2D dir;
            srand(10000);
            // (Vector) Normal to the line
            dir.x_comp()=(float)rand();
            dir.y_comp()=(float)rand();
            dir.normalize();

            // Point on the line
            v.x=rand()/1000.0f;
            v.y=rand()/1000.0f;

            Vector2D dir_p;
            dir_p.x_comp()=v.x;
            dir_p.y_comp()=v.y;
            dir_p.normalize();

            Vector2D dir_q;
            dir_q.x_comp()=q.x;
            dir_q.y_comp()=q.y;
            dir_q.normalize();

            return (dir.dotProduct(dir_p) < dir.dotProduct(dir_q));
        }
};

#endif
