#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <list>
#include <queue>
//#include "basic_graphics.h"

using namespace std;

template <typename E>
class BinarySearchTree
{
protected:
    struct Node   // a node of the tree
    {
        protected:
        E elt; // element value
        Node* par; // parent
        Node* left; // left child
        Node* right; // right child
        Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
        public:
        E value() const {return elt;}
        friend class BinarySearchTree;
    };
public:
    class Position   // position in the tree
    {
    private:
        Node* v; // pointer to the node
    public:
        Position(Node* v = NULL); /* constructor */
        Node& operator*() const; /* get node */
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
    /* ########################################### */
    /*          Implement methods below            */
    /* ########################################### */

    /* draw tree (external nodes are empty and not drawn) */
    int draw(Position p, int x = -1, int y = 0) const;
    /* [01]A add node to tree */
    void add(E data);
    /* [01]B remove node w/ given value from tree */
    void remove(E data);

    // housekeeping functions omitted. . .
protected: // local utilities
    void addRoot(); // add root to empty tree
    void expandExternal(const Position& p); // expand external node
    Position removeAboveExternal(const Position& p); // remove p and parent
    void inorder(Position p, PositionList& pl) const; // inorder utility
    //shortcut names

private:
    Node* _root; // pointer to the root
    int n; // number of nodes
//    typedef BinarySearchTree<E>::Position Position;
//    typedef BinarySearchTree<E>::PositionList PositionList;
};


/* function implementation */
template <typename E>
BinarySearchTree<E>::Position::Position(Node* v) : v(v) {} // constructor

template <typename E>
typename BinarySearchTree<E>::Node& BinarySearchTree<E>::Position::operator*() const// get element
{
    return *v;
}

template <typename E>
typename BinarySearchTree<E>::Position
    BinarySearchTree<E>::Position::left() const // get left child
{
    return Position(v->left);
}

template <typename E>
typename BinarySearchTree<E>::Position
    BinarySearchTree<E>::Position::right() const // get right child
{
    return Position(v->right);
}

template <typename E>
typename BinarySearchTree<E>::Position
    BinarySearchTree<E>::Position::parent() const // get parent
{
    return Position(v->par);
}


template <typename E>
bool BinarySearchTree<E>::Position::isRoot() const // root of the tree?
{
    return v->par == NULL;
}

template <typename E>
bool BinarySearchTree<E>::Position::isExternal() const // an external node?
{
    return v->left == NULL && v->right == NULL;
}

template <typename E>
bool BinarySearchTree<E>::Position::hasLeftChild() const // has a left child?
{
    return v->left != NULL;
}

template <typename E>
bool BinarySearchTree<E>::Position::hasRightChild() const // has a right child?
{
    return v->right != NULL;
}


template <typename E>
BinarySearchTree<E>::BinarySearchTree() // constructor
    : _root(NULL), n(0) { }

template <typename E>
int BinarySearchTree<E>::size() const // number of nodes
{
    return n;
}


template <typename E>
bool BinarySearchTree<E>::empty() const // is tree empty?
{
    return size() == 0;
}

template <typename E>
typename BinarySearchTree<E>::Position
    BinarySearchTree<E>::root() const // get the root
{
    return Position(_root);
}

template <typename E>
void BinarySearchTree<E>::addRoot() // add root to empty tree
{
    _root = new Node;
    _root->left = NULL;
    _root->right = NULL;
    n = 1;
}

template <typename E>
void BinarySearchTree<E>::expandExternal(const Position& p)
{
    Node* v = p.v; // p’s node
    v->left = new Node; // add a new left child
    v->left->par = v; // v is its parent
    v->right = new Node; // and a new right child
    v->right->par = v; // v is its parent
    n += 2; // two more nodes
}

// remove p and parent
template <typename E>
typename BinarySearchTree<E>::Position
    BinarySearchTree<E>::removeAboveExternal(const Position& p)
{
    Node* w = p.v;
    Node* v = w->par; // get p’s node and parent
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root)   // child of root?
    {
        _root = sib; // . . .make sibling root
        sib->par = NULL;
    }
    else
    {
        Node* gpar = v->par; // w’s grandparent
        if (v == gpar->left) gpar->left = sib; // replace parent by sib
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v; // delete removed nodes
    n -= 2; // two fewer nodes
    return Position(sib);
}

template <typename E>
typename BinarySearchTree<E>::PositionList BinarySearchTree<E>::positions() const
{
    PositionList pl;
    inorder(_root, pl); // inorder traversal
    return PositionList(pl); // return resulting list
}

// inorder traversal
template <typename E>
void BinarySearchTree<E>::inorder(Position p, PositionList& pl) const
{
    // traverse left subtree
    if(p.hasLeftChild())
        inorder(p.left(), pl);
    // add this node
    pl.push_back(p);
    // traverse right subtree
    if(p.hasRightChild())
        inorder(p.right(), pl);
}

/* add node to tree */
template <typename E>
void BinarySearchTree<E>::add(E data)
{
    // increment # nodes (n)
}

template <typename E>
void BinarySearchTree<E>::remove(E data)
{
    // Decrement # nodes (n)
}

#endif
