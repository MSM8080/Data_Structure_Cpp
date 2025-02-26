#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include<iostream>
#include <list>
#include <stdlib.h>

using namespace std;

typedef char Elem;

class BinarySearchTree {
	protected:
		struct Node { // a node of the tree
			Elem elt; // element value
			Node* par; // parent
			Node* left; // left child
			Node* right; // right child
			Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
		};
	public:
		class Position { // position in the tree
		private:
			Node* v; // pointer to the node
		public:
			Position(Node* v = NULL); /* constructor */
			Elem& operator*(); /* get element */
			bool operator ==(const Position& p) const; /* Not implemented */ 
			bool operator !=(const Position& p) const; /* Not implemented */ 
			Position left() const; /* get left child */
			Position right() const; /* get right child */
			Position parent() const; /* get parent */
			bool isRoot() const; /* root of the tree? */
			bool isExternal() const; /* an external node? */
            Position sibling() const; /* return Position to sibling */
            bool operator==(Node* m_v); /**/
            bool operator!=(Node* m_v); /**/
			friend class BinarySearchTree; /* give tree access */
		};
		typedef std::list<Position> PositionList; // list of positions
	public:
		BinarySearchTree(); // constructor
		int size() const; // number of nodes
		bool empty() const; // is tree empty?
		Position root() const; // get the root
		PositionList positions() const; // list of nodes
        void addRoot(); // add root to empty tree
		void expandExternal(const Position& p); // expand external node
    	Position removeAboveExternal(const Position& p); // remove p and parent
    	/* added functions */
    	void print_exp_recur(Position p) const; /* print expression recursively */
        float eval_recur(Position p) const ; /* evaluate expression recursively */
        bool isAncestor(Position p1, Position p2) const; /* return true iff p1 is an ancestor of p2 */
        bool isDescendant(Position p1, Position p2) const; /* return true iff p1 is a descendant of p2 */
        PositionList get_path(Position p1, Position p2) const; /* return PositionList containing a path between p1 and p2 */
        bool isSibling(Position p1, Position p2) const; /* return true iff p1 is sibling of p2 */
        int depth_recur(Position p) const; /* calculates depth of a node recursively */
        int depth(Position p) const; /* calculate depth of a node */
        int height_recur(Position p) const; /* calculate tree height recursively */
        int height(Position p) const; /* calculate tree height */
        float eval(Position p) const; /* evaluate expression */
        int from_str_exp_recur(string exp, Position p, int ind = 0); /* convert string expression to a binary tree recursively */
        void from_str_exp(string exp); /* convert string expression to a binary tree */
		// housekeeping functions omitted. . .
		// 1] Destructor
		// ~BinarySearchTree();
		// 2] Copy constructor
		// BinarySearchTree(const BinarySearchTree& other);
		// 3] Assignment operator
		// BinarySearchTree& operator=(const BinarySearchTree& other);
    protected: // local utilities
		void preorder(Node* v, PositionList& pl) const; // preorder utility
	private:
		Node* _root; // pointer to the root
		int n; // number of nodes
};

typedef BinarySearchTree::Position Position;
typedef BinarySearchTree::PositionList PositionList;

#endif