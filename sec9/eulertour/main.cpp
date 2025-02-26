#include <iostream>
#include "basic_graphics.h"
#include "BinarySearchTree.h"
#include "eulertour.h"

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    BinarySearchTree<int>::PositionList pl;
    BinarySearchTree<int>::Position p;
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




    std::list<BinarySearchTree::Position>::iterator
    std::list<BinarySearchTree<int>::Position>::iterator



    /* print nodes (in-order traversal) */
    pl = bst.positions();
    cout << "Binary Search Tree: \n";
    for (std::list<BinarySearchTree<int>::Position>::iterator i = pl.begin();
         i != pl.end(); i++)
    {
        BinarySearchTree<int>::Position p = *i;
        cout << (*p).value() << ' ';

        // cout << (**i).value() << ' ';
    }
    /* test your code here */


//    /* continue execution on any key press */
//    getch();
//    /* clear screen */
//    system("cls");
    /* continue execution on any key press */
    return 0;
}
