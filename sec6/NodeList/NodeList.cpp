#include "NodeList.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
NodeList::Iterator::Iterator(Node* u) // constructor from Node*
    { v = u; }
Elem& NodeList::Iterator::operator*() // reference to the element
    { return v->elem; } // compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
    { return v == p.v; }
bool NodeList::Iterator::operator!=(const Iterator& p) const
    { return v != p.v; } // move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
    { v = v->next; return *this; } // move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
    { v = v->prev; return *this; }
////////////////////////////////////////////////////////////////////////////
NodeList::NodeList() { // constructor
    n = 0; // initially empty
    header = new Node; // create sentinels
    trailer = new Node;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}
int NodeList::size() const // list size
    { return n; }
bool NodeList::empty() const // is the list empty?
    { return (n == 0); }
NodeList::Iterator NodeList::begin() const // begin position is first item
    { return Iterator(header->next); }
NodeList::Iterator NodeList::end() const // end position is just beyond last
    { return Iterator(trailer); }
void NodeList::insert(const NodeList::Iterator& p, const Elem& e)
{
    Node* w = p.v; // p’s node
    Node* u = w->prev; // p’s predecessor
    Node* v = new Node; // new node to insert
    v->elem = e;
    v->next = w; w->prev = v; // link in v before w
    v->prev = u; u->next = v; // link in v after u
    n++;
}
void NodeList::insertFront(const Elem& e) // insert at front
    { insert(begin(), e); }
void NodeList::insertBack(const Elem& e) // insert at rear
    { insert(end(), e); }
void NodeList::erase(const Iterator& p) { // remove p
    Node* v = p.v; // node to remove
    Node* w = v->next; // successor
    Node* u = v->prev; // predecessor
    u->next = w; w->prev = u; // unlink p
    delete v; // delete this node
    n--; // one fewer element
}
void NodeList::eraseFront() // remove first
    { erase(begin()); }
void NodeList::eraseBack() // remove last
    { erase(--end()); }
void NodeList::print()
{

    for(NodeList::Iterator p = begin() ;p != end();++p)
    {
        cout<<*p<<" ";
    }
}
NodeList::Iterator NodeList::get_iterator(int indx)
{
    NodeList::Iterator p = begin();
    for(int i=0;i<=indx;i++)
    {
        if(i == indx)
        {
           // cout<<*p<<endl;
            return p;
        }
        ++p;
    }
    return NULL;
}
void NodeList::copy(NodeList::Iterator src_beg, NodeList::Iterator src_end, NodeList::Iterator dst_beg) // without override
{
    while(src_beg != src_end)
    {
        *dst_beg = *src_beg;
        ++src_beg;
        ++dst_beg;
    }
    *dst_beg = *src_beg;
}
NodeList::~NodeList()
{/*Not implemented*/}
////////////////////////////////////////////////////////////////////////////
