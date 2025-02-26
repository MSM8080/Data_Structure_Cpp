#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <list>
#include <queue>
#include <string>

using namespace std;

//typedef string string;

class BinarySearchTree
{
public:
    struct Node   // a node of the tree
    {
        string elt; // stringent value
        Node* par;
        Node* left;
        Node* right;
        Node* associated_node;
        Node() : elt(), par(NULL), left(NULL), right(NULL), associated_node(NULL) { } // constructor
    };
public:
    class Position   // position in the tree
    {
    private:
        Node* v; // pointer to the node
    public:
        Position(Node* v = NULL); /* constructor */
        string& operator*(); /* get string name */
        string& operator!(); /* get string number */
        bool operator==(const Position p) const; /* Not implemented */
        bool operator!=(const Position p) const; /* Not implemented */
        operator bool() const; /* Not implemented */
        Position left() const; /* get left child */
        Position right() const; /* get right child */
        Position parent() const; /* get parent */
        bool isRoot() const; /* root of the tree? */
        bool isExternal() const; /* an external node? */
        bool hasLeftChild() const; /* has a left child? */
        bool hasRightChild() const; /* has a right child? */
        friend class BinarySearchTree; /* give tree access */
    };
    typedef std::list<Position> PositionList; // list of positions
public:
    BinarySearchTree(); // constructor
    int size() const; // number of nodes
    bool empty() const; // is tree empty?
    Position root() const; // get the root
    PositionList positions() const; // list of nodes
    // by me
    Node* lastAdded();
    Node* lastRemoved();
    void add(string data);
    void remove(string data);
    PositionList BinarySearch(string data) const;
    PositionList BinaryPrefixSearch(string DataPrefix) const;
    void InorderSearch(Position p, string DataPrefix, PositionList& pl) const;
/* ########################################### */
/*            problems start here              */
/* ########################################### */


    /* [02] returns position of the maximum stringent in the tree */
    Position max() const;
    /* [03] returns position of the minimum stringent in the tree */
    Position min() const;
    /* [04] returns true if value is in the tree */
    bool exist(string val) const;
    /* [05] returns position of the (inorder predecessor) largest stringent less than the value in p */
    Position inorder_predecessor(Position p) const;
    /* [06] returns position of the (inorder successor) smallest stringent larger than the value in p */
    Position inorder_successor(Position p) const;
    /* [07] count: returns the number of stored stringents/nodes (traverse the tree). */
    unsigned int count() const;
    /* [08]/[09] opereator [] positive/negative index */
    string operator [](int index) const;
    /* [10] mean of all stringents */
    double mean() const;

    // housekeeping functions omitted. . .
protected: // local utilities
    void addRoot(); // add root to empty tree
    void expandExternal(const Position& p); // expand external node
    Position removeAboveExternal(const Position& p); // remove p and parent
    void inorder(Position p, PositionList& pl) const; // inorder utility
private:
    Node* _root; // pointer to the root
    int n; // number of nodes
    Node* last_added;
    Node* last_removed;
};

typedef BinarySearchTree::Position Position;
typedef BinarySearchTree::PositionList PositionList;
typedef BinarySearchTree::Node Node;

#endif
