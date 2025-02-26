#include "LinkedBinaryTree.h"

Position::Position(Node* v) : v(v) {} // constructor

Elem& BinarySearchTree::Position::operator*() // get element
{
    return v->elt;
}

bool BinarySearchTree::Position::operator==(const Position& p) const /* Not implemented */
{
    return (v == p.v);
}

bool BinarySearchTree::Position::operator!=(const Position& p) const /* Not implemented */
{
    return (v != p.v);
}

Position Position::left() const // get left child
{
    return Position(v->left);
}

Position Position::right() const // get right child
{
    return Position(v->right);
}

Position Position::parent() const // get parent
{
    return Position(v->par);
}

bool Position::isRoot() const // root of the tree?
{
    return v->par == NULL;
}

bool Position::isExternal() const // an external node?
{
    return v->left == NULL && v->right == NULL;
}

/* return Position to sibling */
Position Position::sibling() const
{

}

BinarySearchTree::BinarySearchTree() // constructor
    : _root(NULL), n(0) { }

int BinarySearchTree::size() const // number of nodes
{
    return n;
}

bool BinarySearchTree::empty() const // is tree empty?
{
    return size() == 0;
}

Position BinarySearchTree::root() const // get the root
{
    return Position(_root);
}

void BinarySearchTree::addRoot() // add root to empty tree
{
    _root = new Node;
    n = 1;
}

void BinarySearchTree::expandExternal(const Position& p)
{
    Node* v = p.v; // p’s node
    v->left = new Node; // add a new left child
    v->left->par = v; // v is its parent
    v->right = new Node; // and a new right child
    v->right->par = v; // v is its parent
    n += 2; // two more nodes
}

// remove p and parent
Position BinarySearchTree::removeAboveExternal(const Position& p)
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

PositionList BinarySearchTree::positions() const
{
    PositionList pl;
    preorder(_root, pl); // preorder traversal
    return PositionList(pl); // return resulting list
}

/* print expression recursively*/
void BinarySearchTree::print_exp_recur(Position p) const
{
    if(!p.isExternal())
    {
        cout<<"(";
        print_exp_recur(p.left());
    }
    cout<<*p;
    if(!p.isExternal())
    {
        print_exp_recur(p.right());
        cout<<")";
    }
}

/* evaluate expression recursively*/
float BinarySearchTree::eval_recur(Position p) const
{
    //cout<<*p<<endl;
    if(!p.isExternal())
    {
        float x = eval_recur(p.left());
        float y = eval_recur(p.right());
        if(*p == '+')
            return (x+y);
        if(*p == '-')
            return (x-y);
        if(*p == '*')
            return (x*y);
        if(*p == '/')
            return (x/y);
    }
    else
    {
        return float(*p-'0');

    }
}

/* return true if p1 is an ancestor of p2 */
bool BinarySearchTree::isAncestor(Position p1, Position p2) const
{

}

/* return true iff p1 is a descendant of p2 */
bool BinarySearchTree::isDescendant(Position p1, Position p2) const
{

}

/* return PositionList containing a path between p1 and p2 */
PositionList BinarySearchTree::get_path(Position p1, Position p2) const
{

}

/* return true iff p1 is sibling of p2 */
bool BinarySearchTree::isSibling(Position p1, Position p2) const
{

}

/* calculate depth of a node recursively */
int BinarySearchTree::depth_recur(Position p) const
{

}

/* calculate depth of a node */
int BinarySearchTree::depth(Position p) const
{

}

/* calculate tree height recursively */
int BinarySearchTree::height_recur(Position p) const
{

}

/* calculate tree height */
int BinarySearchTree::height(Position p) const
{

}

/* evaluate expression */
float BinarySearchTree::eval(Position p) const
{

}

/* convert string expression to a binary tree */
void BinarySearchTree::from_str_exp(string exp)
{

}

/* convert string expression to a binary tree recursively */
int BinarySearchTree::from_str_exp_recur(string exp, Position p, int ind)
{

}

// preorder traversal
void BinarySearchTree::preorder(Node* v, PositionList& pl) const
{
    pl.push_back(Position(v)); // add this node
    if (v->left != NULL) // traverse left subtree
        preorder(v->left, pl);
    if (v->right != NULL) // traverse right subtree
        preorder(v->right, pl);
}
