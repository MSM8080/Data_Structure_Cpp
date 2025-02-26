#include <iostream>
#include "binarysearchtree.h"
#include "basic_graphics.h"
#include <iomanip>
//#define testcase1
//#define testcase2
//#define testcase3
//#define testcase4
//#define testcase5
//#define testcase6
//#define testcase7
//#define testcase8
//#define testcase9
//#define testcase10
using namespace std;

int main()
{
    BinarySearchTree bst,bst1;
    BinarySearchTree::PositionList pl,p2;
    Position p;
    bst.add(50);
    bst.add(25);
    bst.add(34);
    bst.add(75);
    bst.add(12);
    bst.add(36);
    bst.add(150);
    bst.add(6);
    bst.add(100);
    bst.add(40);
    bst.add(23);
    bst.add(80);
    bst.add(200);


    bst1.add(50);
    bst1.add(25);
    bst1.add(34);
    bst1.add(75);
    bst1.add(12);
    bst1.add(36);
    bst1.add(150);
    bst1.add(6);
    bst1.add(100);
    bst1.add(40);
    bst1.add(23);
    bst1.add(80);
    bst1.add(200);

    /* print nodes (in-order traversal) */
    /*system("cls");*/
    pl = bst.positions();
    cout << "Expected Binary Search Tree (ADD) A: 6 12 23 25 34 36 40 50 75 80 100 150 200 \n your output :";
    for (std::list<BinarySearchTree::Position>::iterator i = pl.begin(); i != pl.end(); i++)
    {
        cout << **i << ' ';
    }
#ifdef testcase1
    bst1.remove(40);
        p2 = bst1.positions();
    cout << "\n\n Expected Binary Search Tree (remove) A: 6 12 23 25 34 36 50 75 80 100 150 200 \n your output :";
    for (std::list<BinarySearchTree::Position>::iterator i = p2.begin(); i != p2.end(); i++)
    {
        cout << **i << ' ';
    }
        bst1.remove(150);
    p2 = bst1.positions();
    cout << "\n\n Expected Binary Search Tree (remove) B: 6 12 23 25 34 36 50 75 80 100 200 \n your output :";
    for (std::list<BinarySearchTree::Position>::iterator i = p2.begin(); i != p2.end(); i++)
    {
        cout << **i << ' ';
    }
    bst1.remove(50);
    p2 = bst1.positions();
    cout << "Expected Binary Search Tree (remove) C: 6 12 23 25 34 36 75 80 100 200 \n your output :";
    for (std::list<BinarySearchTree::Position>::iterator i = p2.begin(); i != p2.end(); i++)
    {
        cout << **i << ' ';
    }
    bst1.remove(37);
    p2 = bst1.positions();
    cout << "\n\n Expected Binary Search Tree (remove) D: 6 12 23 25 34 36 75 80 100 200 \n your output :";
    for (std::list<BinarySearchTree::Position>::iterator i = p2.begin(); i != p2.end(); i++)
    {
        cout << **i << ' ';
    }
#endif // testcase1
#ifdef testcase2
    /* [03] max() */
    cout << "\n\n[03] max() \nExpected output: 200"
         << "\n<<your output>>: " << *bst.max();
#endif
#ifdef testcase3
    /* [04] min() */
    cout << "\n\n[04] min() \nExpected output: 6"
         << "\n<<your output>>: " << *bst.min();
#endif
#ifdef testcase4
    /* [05] exist() */
    cout << "\n\n[05]a exist() \nExpected output: true"
         << "\n<<your output>>: " << (bst.exist(23)?"true":"false");
    cout << "\n\n[05]b exist() \nExpected output: true"
         << "\n<<your output>>: " << (bst.exist(37)?"true":"false");
#endif
#ifdef testcase5
    /* [06]A inorder_predecessor() */
    /* element: 50 */
    p = bst.root();
    cout << "\n\n[06]A inorder_predecessor() "<< *p<< " \nExpected output: 40"
         << "\n<<your output>>: " << *bst.inorder_predecessor(p);

    /* [06]B inorder_predecessor() */
    /* element 6 */
    /* 3 levels down to the left (min.) */
    for (int i=0; i<3; i++)
        p = p.left();
    cout << "\n\n[06]B inorder_predecessor() "<< *p<< "\nExpected output: None"
         << "\n<<your output>>: ";
    /* store position */
    p = bst.inorder_predecessor(p);
    /* empty node */
    if(!p)
        {cout <<"None";}
    else
        {cout << *p;}

    /* [06]C inorder_predecessor() */
    /* element: 200 */
    p = bst.root();
    /* 3 levels down to the right (max.) */
    for (int i=0; i<3; i++)
        p = p.right();
    cout << "\n\n[06]C inorder_predecessor() "<< *p<< ":\nExpected output: 150"
         << "\n<<your output>>: " << *bst.inorder_predecessor(p);

    /* [06]D inorder_predecessor() */
    /* element: 150 */
    /* 1 level up */
    p = p.parent();
    cout << "\n\n[06]D inorder_predecessor() "<< *p<< ":\nExpected output: 100"
         << "\n<<your output>>: " << *bst.inorder_predecessor(p);

    /* [06]E inorder_predecessor()*** */
    /* element: 80 */
    /* 2 levels down to the left */
    for (int i=0; i<2; i++)
        p = p.left();
    cout << "\n\n[06]E inorder_predecessor() "<< *p<< " \nExpected output: 75"
         << "\n<<your output>>: " << *bst.inorder_predecessor(p);
#endif
#ifdef testcase6

    /* [07]A inorder_successor() */
    /* element: 50 */
    p = bst.root();
    cout << "\n\n[07]A inorder_successor() "<< *p<< " \nExpected output: 75"
         << "\n<<your output>>: " << *bst.inorder_successor(p);

    /* [07]B inorder_successor() */
    /*  element 200 */
    /* 3 levels down to the right (max.) */
    for (int i=0; i<3; i++)
        p = p.right();
    cout << "\n\n[07]B inorder_successor() "<< *p<< "\nExpected output: None"
         << "\n<<your output>>: ";
    /* store position */
    p = bst.inorder_successor(p);
    /* empty node */
    if(!p)
        {cout <<"None";}
    else
        {cout << *p;}

    /* [07]C inorder_successor() */
    /* element: 6 */
    p = bst.root();
    /* 3 levels down to the right (max.) */
    for (int i=0; i<3; i++)
        p = p.left();
    cout << "\n\n[07]C inorder_successor() "<< *p<< ":\nExpected output: 12"
         << "\n<<your output>>: " << *bst.inorder_successor(p);

    /* [07]D inorder_successor() */
    /* element: 25 */
    /* 2 level up */
    for (int i=0; i<2; i++)
        p = p.parent();
    cout << "\n\n[07]D inorder_successor() "<< *p<< ":\nExpected output: 34"
         << "\n<<your output>>: " << *bst.inorder_successor(p);

    /* [07]E inorder_successor()*** */
    /* element: 40 */
    /* 2 levels down to the right */
    for (int i=0; i<3; i++)
        p = p.right();
    cout << "\n\n[07]E inorder_successor() "<< *p<< " \nExpected output: 50"
         << "\n<<your output>>: " << *bst.inorder_successor(p);
#endif
#ifdef testcase7
    /* [08] count() */
    cout << "\n\n[08] count() \nExpected output: 13"
         << "\n<<your output>>: " << bst.count();
#endif
#ifdef testcase8
    /* [09] cperator []() positive index */
    cout << "\n\n[09] operator []() \nExpected output: 6 12 23 25 34 36 40 50 75 80 100 150 200"
         << "\n<<your output>>: ";
    for (int i=0; i<13; i++)
        { cout << bst[i] << ' '; }
#endif
#ifdef testcase9
    /* [10] cperator []() negative index */
    cout << "\n\n[10] operator []() \nExpected output: 200 150 100 80 75 50 40 36 34 25 23 12 6"
         << "\n<<your output>>: ";
    for (int i=1; i<14; i++)
        { cout << bst[-i] << ' '; }
#ifdef testcase10
    /* [11] mean() */
    cout << "\n\n[11] mean() \nExpected output: 63.9231"
    << "\n<<your output>>: " << bst.mean();
#endif
    /* continue execution on any key press */
    getch();
    return 0;
}
