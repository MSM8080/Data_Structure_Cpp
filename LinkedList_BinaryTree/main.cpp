#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;
/*
 * Test the functions below yourself
 * #9:isSibling #10:sibling #11:path
 */
int main()
{
    BinarySearchTree bst, bst_exp_recur, bst_exp;
    string exp = "((((3+1)*3)/((9-5)+2))-((3*(7-4))+6))";
    // add root to empty binary tree
    bst.addRoot();
    Position p[32];
    // get root position
    p[0] = bst.root();
    // assign data to root
    *p[0] = '-';
    // expand root
    bst.expandExternal(p[0]);
    // level 1
    p[1] = p[0].left();
    p[2] = p[0].right();
    // assign data to nodes at level 1
    *p[1] = '/';
    *p[2] = '+';
    // expand nodes at level 1
    bst.expandExternal(p[1]);
    bst.expandExternal(p[2]);
    // level 2
    p[3] = p[1].left();
    p[4] = p[1].right();
    p[5] = p[2].left();
    p[6] = p[2].right();
    // assign data to nodes at level 2
    *p[3] = '*';
    *p[4] = '+';
    *p[5] = '*';
    *p[6] = '6';
    // expand nodes at level 2
    bst.expandExternal(p[3]);
    bst.expandExternal(p[4]);
    bst.expandExternal(p[5]);
    // level 3
    p[7] = p[3].left();
    p[8] = p[3].right();
    p[9] = p[4].left();
    p[10] = p[4].right();
    p[11] = p[5].left();
    p[12] = p[5].right();
    // assign data to nodes at level 3
    *p[7] = '+';
    *p[8] = '3';
    *p[9] = '-';
    *p[10] = '2';
    *p[11] = '3';
    *p[12] = '-';
    // expand nodes at level 3
    bst.expandExternal(p[7]);
    bst.expandExternal(p[9]);
    bst.expandExternal(p[12]);
    // level 4
    p[13] = p[7].left();
    p[14] = p[7].right();
    p[15] = p[9].left();
    p[16] = p[9].right();
    p[17] = p[12].left();
    p[18] = p[12].right();
    // assign data to nodes at level 4
    *p[13] = '3';
    *p[14] = '1';
    *p[15] = '9';
    *p[16] = '5';
    *p[17] = '7';
    *p[18] = '4';
    /*-------------------------------------------------------------------------------------------------*/
    /* [01] print expression recursively*/
    cout << "\n\n[01] Print Exp (Recursively) \nExpected output: ((((3+1)*3)/((9-5)+2))-((3*(7-4))+6))";
    cout << "\n<<your output>>: ";
    bst.print_exp_recur(p[0]);
    
    /* [02] evaluate expression recursively*/
    cout << "\n\n[02] Eval Exp (Recursively) \nExpected output: -13"
         << "\n<<your output>>: " << bst.eval_recur(p[0]);

    /* [03] depth_recur */
    cout << "\n\n[03] depth_recur() \nExpected output: 4"
         << "\n<<your output>>: " << bst.depth_recur(p[15]);
    
    /* [04] depth (non-recursive) */
    cout << "\n\n[04] depth() \nExpected output: 4"
         << "\n<<your output>>: " << bst.depth(p[15]);
    
    /* [05]A height_recur */
    cout << "\n\n[05]A height_recur() \nExpected output: 4"
         << "\n<<your output>>: " << bst.height_recur(p[0]);
    /* [05]B height_recur */
    cout << "\n\n[05]B height_recur() \nExpected output: 3"
         << "\n<<your output>>: " << bst.height_recur(p[1]);
    /* [05]C height_recur */
    cout << "\n\n[05]C height_recur() \nExpected output: 0"
         << "\n<<your output>>: " << bst.height_recur(p[18]);
    
    /* [06]A height */
    cout << "\n\n[06]A height() \nExpected output: 4"
         << "\n<<your output>>: " << bst.height(p[0]);
    /* [06]B height */
    cout << "\n\n[06]B height() \nExpected output: 3"
         << "\n<<your output>>: " << bst.height(p[1]);
    /* [06]C height */
    cout << "\n\n[06]C height() \nExpected output: 0"
         << "\n<<your output>>: " << bst.height(p[15]);

    /* [07]A isAncestor */
    cout << "\n\n[07]A isAncestor() \nExpected output: true"
         << "\n<<your output>>: " << (bst.isAncestor(p[2], p[2])?"true": "false");
    /* [07]B isAncestor */
    cout << "\n[07]B isAncestor() \nExpected output: true"
         << "\n<<your output>>: " << (bst.isAncestor(p[1], p[15])?"true": "false");
    /* [07]C isAncestor */
    cout << "\n[07]C isAncestor() \nExpected output: false"
         << "\n<<your output>>: " << (bst.isAncestor(p[2], p[15])?"true": "false");
    
    /* [08] isDescendant */
    cout << "\n\n[08] isDescendant() \nExpected output: true"
         << "\n<<your output>>: " << (bst.isAncestor(p[15], p[15])?"true": "false");
    
    /* [12] evaluate expression (Non-recursive) */
     cout << "\n\n[12] Eval Exp (Non-recursive) \nExpected output: -13"
         << "\n<<your output>>: " << bst.eval(p[0]);
            
    /* [13] from_str_exp_recur */
    bst_exp_recur.addRoot();
    bst_exp_recur.from_str_exp_recur(exp, bst_exp_recur.root());
    cout << "\n\n[13] from_str_exp_recur() \nExpected output: " << exp
         << "\n<<your output>>: ";
    bst_exp_recur.print_exp_recur(bst_exp_recur.root());
    
    /* [14] from_str_exp */
    bst_exp.from_str_exp(exp);
    cout << "\n\n[14] from_str_exp() \nExpected output: " << exp
         << "\n<<your output>>: ";
    bst_exp.print_exp_recur(bst_exp.root());
    return 0;
}
