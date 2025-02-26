#include "binarysearchtree.h"

Position::Position(Node* v) : v(v) {} // constructor

Elem& BinarySearchTree::Position::operator*() // get element
{
    return v->elt;
}

bool BinarySearchTree::Position::operator==(const Position p) const /* Not implemented */
{

}

bool BinarySearchTree::Position::operator!=(const Position p)  const /* Not implemented */
{

}

BinarySearchTree::Position::operator bool()  const /* Not implemented */
{

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
void BinarySearchTree::add(Elem data)
{
    if(empty())
    {
        _root = new Node;
        _root->elt = data;
    }
    else
    {
        Position crr = root();
        while(!crr.isExternal())
        {
            if(data < *crr)
                crr = crr.left();
            else
                crr = crr.right();
        }
        if(data < *crr)
            {
                    crr.v->left = new Node;
                    crr.v->left->par = crr.v;
                    crr = crr.left();
                    *crr = data;
            }
        else
            {
                    crr.v->right = new Node;
                    crr.v->right->par = crr.v;
                    crr = crr.right();
                    *crr = data;
            }
    }
//
//    if(empty())
//    {
//        addRoot();
//        Position crr = root();
//        expandExternal(crr);
//        *crr = data;
//    }
//    else
//    {
//        Position crr = root();
//        while(  !(crr.left().isExternal()  &&  crr.right().isExternal())    )
//        {
//            if(data < *crr)
//            {
//                crr = crr.left();
//                if(crr.isExternal())
//                    break;
//            }
//            else
//            {
//                //cout<<data<<endl;
//                crr = crr.right();
//                if(crr.isExternal())
//                    break;
//            }
//        }
//        if(crr.isExternal())
//        {
//            *crr = data;
//            expandExternal(crr);
//        }
//        else if(data < *crr)
//        {
//            crr = crr.left();
//            *crr = data;
//            //cout<<"data "<<*crr<<endl;
//            expandExternal(crr);
//        }
//        else
//        {
//            crr = crr.right();
//            *crr = data;
//            //cout<<"data "<<*crr<<endl;
//            expandExternal(crr);
//        }
//    }

}

/* [01]B remove node from tree */
void BinarySearchTree::remove(Elem data)
{
    if(empty())
        return;
    else
    {
        Position crr = root();
        while(  !(crr.left().isExternal()  &&  crr.right().isExternal())    )
        {
            //cout<<*crr<<endl;
            if(*crr == data)
                break;
            else if(data < *crr)
            {
                crr = crr.left();
                if(crr.isExternal())
                    break;
            }
            else
            {
                //cout<<data<<endl;
                crr = crr.right();
                if(crr.isExternal())
                    break;
            }
        }

        cout<<"\n"<<*crr;

        if((crr.left().isExternal()  &&  crr.right().isExternal()))
        {
            Position papa = crr.parent();
            if(*crr == *(papa.left()))
            {
                papa.left() = NULL;
                delete crr.v;
            }
            else
            {
                papa.right() = NULL;
                delete crr.v;
            }

//            crr.v = new Node;
//            crr.v->par = papa;
//            crr.v = new Node;
//            crr.v->par = papa;
            //cout<<"\nhi\n";
            //cout<<"\n"<<*crr<<endl;
            return;
        }
        else
        {
            Position gedo, left_child, right_child;
            gedo = crr.parent();
            left_child = crr.left();
            right_child = crr.right();

//            cout<<"\n"<<*gedo<<endl;
//            cout<<"\n"<<*left_child<<endl;
//            cout<<"\n"<<*right_child<<endl;


            if(*crr == *(gedo.left()))
            {
                gedo.left() = left_child;
                delete crr.v;
                crr = gedo.left();
                while(  !(crr.left().isExternal()  &&  crr.right().isExternal())   )
                {
                    crr = crr.right();
                    if(crr.isExternal())
                        break;
                }
                if(crr.isExternal())
                {
                    crr = right_child;
                    return;
                }
                else
                {
                    crr.right() = right_child;
                    return;
                }
            }
            else
            {
                *gedo.right() = *left_child;
                gedo.right().v->left = left_child.v->left;
                gedo.right().v->right = left_child.v->right;

//                cout<<endl;
//                cout<<*(gedo.right())<<endl;
//                cout<<*(gedo.right().parent())<<endl;
//                cout<<"\n"<<*(gedo.right().left())<<endl;
//                cout<<"\n"<<*(gedo.right().right())<<endl;

                delete crr.v;
                crr = gedo.right();
                while(  !(crr.left().isExternal()  &&  crr.right().isExternal())   )
                {
                    crr = crr.right();
                    if(crr.isExternal())
                        break;
                }
                if(crr.isExternal())
                {
                    crr = right_child;
                    return;
                }
                else
                {
                    crr.right() = right_child;
                    return;
                }
            }
        }
    }
}

/* [02] returns position of the maximum element in the tree */
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

/* [03] returns position of the minimum element in the tree */
Position BinarySearchTree::min() const
{
    Position m;
    if(empty())
    {
        return NULL;
    }
    else
    {
        m = root();
        while(!m.left().isExternal()  &&   !m.right().isExternal())
        {
                m = m.left();
        }
        if((*(m.left())   <   *m)    &&    *(m.left()) != 0)
            return m.left();
        else
            return m;
    }
}

/* [04] returns true if value is in the tree */
bool BinarySearchTree::exist(Elem val) const
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

/* [05] returns position of the (inorder predecessor) largest element less than the value in p */
Position BinarySearchTree::inorder_predecessor(Position p) const
{ }

/* [06] returns position of the (inorder successor) smallest element larger than the value in p */
Position BinarySearchTree::inorder_successor(Position p) const
{ }

/* [07] count: returns the number of stored elements/nodes (traverse the tree). */
unsigned int BinarySearchTree::count() const
{ }

/* [08]/[09] opereator [] positive/negative index */
Elem BinarySearchTree::operator [](int index) const
{ }

/* [10] mean of all elements */
double BinarySearchTree::mean() const
{ }
