#include "binarysearchtree.h"

Position::Position(Node* v) : v(v) {} // constructor

string& BinarySearchTree::Position::operator*() // get stringent
{
    return v->elt;
}

string& BinarySearchTree::Position::operator!()
{
    return v->associated_node->elt;
}

bool BinarySearchTree::Position::operator==(const Position p) const /* Not implemented */
{

}

bool BinarySearchTree::Position::operator!=(const Position p)  const /* Not implemented */
{

}

//bool BinarySearchTree::Position::operator()  const /* Not implemented */
//{
//
//}

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

bool Position::hasLeftChild() const // has a left child?
{
    return v->left != NULL;
}

bool Position::hasRightChild() const // has a right child?
{
    return v->right != NULL;
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
    inorder(_root, pl); // inorder traversal
    return PositionList(pl); // return resulting list
}

// what is last node
Node* BinarySearchTree::lastAdded()
{
    return last_added;
}

Node* BinarySearchTree::lastRemoved()
{
    return last_removed;
}

// inorder traversal
void BinarySearchTree::inorder(Position p, PositionList& pl) const
{
    // traverse left subtree
    if(p.hasLeftChild())
        inorder(p.left(), pl);
    // Push inorder / external
    // add this node
    pl.push_back(p);
    // traverse right subtree
    if(p.hasRightChild())
        inorder(p.right(), pl);
}
/* ########################################### */
/*          Implement methods below            */
/* ########################################### */

/* [01]A add node to tree */
void BinarySearchTree::add(string data)
{
    if(empty())
    {
        addRoot();
        Position r = root();
        *r = data;
        last_added = _root;
    }
    else
    {
        Position crr = root();
        while(!crr.isExternal())
        {
            if(data < *crr)
            {
                if(crr.v->left == NULL) break;
                crr = crr.left();
            }

            else
            {
                if(crr.v->right == NULL) break;
                crr = crr.right();
            }
        }
        if(data < *crr)
            {
                    crr.v->left = new Node;
                    crr.v->left->par = crr.v;
                    crr = crr.left();
                    *crr = data;
                    last_added = crr.v;
                    n++;
            }
        else
            {
                    crr.v->right = new Node;
                    crr.v->right->par = crr.v;
                    crr = crr.right();
                    *crr = data;
                    last_added = crr.v;
                    n++;
            }
    }
}

/* [01]B remove node from tree */
void BinarySearchTree::remove(string data)
{
    if(empty())
        return;
    else
    {
        Position crr = root();
        while(!crr.isExternal())
        {
            if(data < *crr)
            {
                if(crr.v->left == NULL) break;
                crr = crr.left();
            }

            else if(data > *crr)
            {
                if(crr.v->right == NULL) break;
                crr = crr.right();
            }
            else // data == *crr
                break;
        }
        if(crr.isRoot())          // root
        {
            if(size() == 1) // no childs
            {
                last_removed = crr.v->associated_node;
                delete crr.v;
                n--;
                return;
            }
            else if(crr.hasLeftChild() && crr.hasRightChild())  // two childs
            {
                Position right_child = crr.right();
                Position left_child = crr.left();
                last_removed = crr.v->associated_node;
                delete crr.v;
                n--;
                _root = right_child.v;
                while(right_child.hasLeftChild())
                {
                    right_child = right_child.left();
                }
                right_child.v->left = left_child.v;
                return;
            }
            else if(crr.hasLeftChild())         // has only left child
            {
                _root = crr.v->left;
                last_removed = crr.v->associated_node;
                delete crr.v;
                n--;
                return;
            }
            else                                // has only right child
            {
                _root = crr.v->right;
                last_removed = crr.v->associated_node;
                delete crr.v;
                n--;
                return;
            }
        }
        else if(crr.isExternal())     // external
        {
            Position papa = crr.parent();
            if(papa.v->left == crr.v)  // check left or right child for papa
            {
                papa.v->left = NULL;
                last_removed = crr.v->associated_node;
                n--;
                delete crr.v;
            }
            else
            {
                papa.v->right = NULL;
                last_removed = crr.v->associated_node;
                n--;
                delete crr.v;
            }
        }
        else
        {
            if(crr.hasLeftChild() && crr.hasRightChild())  // two childs
            {
                Position right_child = crr.right();
                Position left_child = crr.left();
                Position gedo = crr.parent();
                if(gedo.v->left == crr.v)  // check crr is left or right child for gedo
                {
                    gedo.v->left = right_child.v;
                }
                else
                {
                    gedo.v->right = right_child.v;
                }
                right_child.v->par = gedo.v;
                last_removed = crr.v->associated_node;
                n--;
                delete crr.v;
                while(right_child.hasLeftChild())
                {
                    right_child = right_child.left();
                }
                right_child.v->left = left_child.v;
                return;
            }
            else if(crr.hasLeftChild())         // has only left child
            {
                Position left_child = crr.left();
                Position gedo = crr.parent();
                if(gedo.v->left == crr.v)  // check crr is left or right child for gedo
                {
                    gedo.v->left = left_child.v;
                }
                else
                {
                    gedo.v->right = left_child.v;
                }
                left_child.v->par = gedo.v;
                last_removed = crr.v->associated_node;
                n--;
                delete crr.v;
                return;
            }
            else                                // has only right child
            {
                Position right_child = crr.right();
                Position gedo = crr.parent();
                if(gedo.v->left == crr.v)  // check crr is left or right child for gedo
                {
                    gedo.v->left = right_child.v;
                }
                else
                {
                    gedo.v->right = right_child.v;
                }
                right_child.v->par = gedo.v;
                last_removed = crr.v->associated_node;
                n--;
                delete crr.v;
                return;
            }
        }
   }
}

/* [02] returns position of the maximum stringent in the tree */
Position BinarySearchTree::max() const
{
    Position m;
    if(empty())
    {
        return NULL;
    }
    else
    {
        m = root();
        while(  !(m.left().isExternal()  &&  m.right().isExternal())    )
        {
                m = m.right();
        }
        if(*(m.right())   >   *m)
            return m.right();
        else
            return m;
    }
}

/* [03] returns position of the minimum stringent in the tree */
Position BinarySearchTree::min() const
{
//    Position m;
//    if(empty())
//    {
//        return NULL;
//    }
//    else
//    {
//        m = root();
//        while(!m.left().isExternal()  &&   !m.right().isExternal())
//        {
//                m = m.left();
//        }
//        if((*(m.left())   <   *m)    &&    *(m.left()) != 0)
//            return m.left();
//        else
//            return m;
//    }
}

/* [04] returns true if value is in the tree */
bool BinarySearchTree::exist(string val) const
{

    if(empty())
    {
        return false;
    }
    else
    {
        Position crr = root();
        while(  !(crr.left().isExternal()  &&  crr.right().isExternal())  )
        {
            //cout<<*crr<<endl;
            if(val < *crr)
            {
                crr = crr.left();
            }
            else if(val == *crr)
                return true;
            else
            {
                crr = crr.right();
            }
        }
        if(val == *crr)
            return true;
        else
            return false;
    }
}

/* [05] returns position of the (inorder predecessor) largest stringent less than the value in p */
Position BinarySearchTree::inorder_predecessor(Position p) const
{ }

/* [06] returns position of the (inorder successor) smallest stringent larger than the value in p */
Position BinarySearchTree::inorder_successor(Position p) const
{ }

/* [07] count: returns the number of stored stringents/nodes (traverse the tree). */
unsigned int BinarySearchTree::count() const
{ }

/* [08]/[09] opereator [] positive/negative index */
string BinarySearchTree::operator [](int index) const
{ }

/* [10] mean of all stringents */
double BinarySearchTree::mean() const
{ }

PositionList BinarySearchTree::BinarySearch(string data) const
{
    PositionList pl;
    if(empty())
        return pl;
    else
    {
        Position crr = root();
        while(!crr.isExternal())
        {
            if(data < *crr)
            {
                if(crr.v->left == NULL) break;
                crr = crr.left();
            }

            else if(data > *crr)
            {
                if(crr.v->right == NULL) break;
                crr = crr.right();
            }
            else // data == *crr
                break;
        }
        if(data == *crr) // found
        {
            pl.push_back(crr);
            return pl;
        }

        else  // not found
        {
            return pl;
        }
    }
}

PositionList BinarySearchTree::BinaryPrefixSearch(string DataPrefix) const
{
    PositionList pl;
    if(empty())
        return pl;
    else
    {
        Position crr = root();
        while(!crr.isExternal())
        {
            if(((*crr).compare(0,3,DataPrefix)) == 0) // found by prefix
                break;
            if(DataPrefix < *crr)
            {
                if(crr.v->left == NULL) break;
                crr = crr.left();
            }

            else if(DataPrefix > *crr)
            {
                if(crr.v->right == NULL) break;
                crr = crr.right();
            }
            else // data == *crr
                break;
        }
        if(((*crr).compare(0,3,DataPrefix)) == 0) // found by  prefix
        {
            pl.push_back(crr);
            return pl;
        }
        else  // not found by prefix
        {
            return pl;
        }
    }
}

void BinarySearchTree::InorderSearch(Position p, string DataPrefix, PositionList& pl) const
{
    // traverse left subtree
    if(p.hasLeftChild())
        InorderSearch(p.left(), DataPrefix, pl);
    // Push inorder / external
    // add this node
    if(((*p).compare(0,3,DataPrefix)) == 0) // found by  prefix
    {
        pl.push_back(p);
    }
    // traverse right subtree
    if(p.hasRightChild())
        InorderSearch(p.right(),DataPrefix, pl);
}
