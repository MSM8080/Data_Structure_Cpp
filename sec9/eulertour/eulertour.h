#ifndef EULERTOUR_H_INCLUDED
#define EULERTOUR_H_INCLUDED

#include "binarysearchtree.h"
template <typename E, typename R>		// element and result types
class EulerTour  				// a template for Euler tour
{
protected:
    struct Result  				// stores tour results
    {
        R leftResult;				// result from left subtree
        R rightResult;				// result from right subtree
        R finalResult; 				// combined result
    };
    typedef BinarySearchTree<E> BinarySearchTree;		// the tree
    typedef typename BinarySearchTree::Position Position; // a position in the tree
protected:					// data member
    const BinarySearchTree* tree;			// pointer to the tree
public:
    void initialize(const BinarySearchTree& T) 	// initialize
        {tree = &T;}
protected:					// local utilities
    R eulerTour(const Position& p) const;	// perform the Euler tour
    // functions given by subclasses
    virtual void visitExternal(const Position& p, Result& r) const {}
    virtual void visitLeft(const Position& p, Result& r) const {}
    virtual void visitBelow(const Position& p, Result& r) const {}
    virtual void visitRight(const Position& p, Result& r) const {}
    Result initResult() const
        {return Result();}
    R result(const Result& r) const
        {return r.finalResult;}
};

/* functions */
template <typename E, typename R>      // do the tour
R EulerTour<E, R>::eulerTour(const Position& p) const
{
    Result r = initResult();
    if (p.isExternal()) {            // external node
        visitExternal(p, r);
    }
    else {                  // internal node
        visitLeft(p, r);
        if (p.hasLeftChild())
            r.leftResult = eulerTour(p.left());   // recurse on left
        visitBelow(p, r);
        if (p.hasRightChild())
            r.rightResult = eulerTour(p.right()); // recurse on right
        visitRight(p, r);
    }
    return result(r);
}
#endif // EULERTOUR_H_INCLUDED
