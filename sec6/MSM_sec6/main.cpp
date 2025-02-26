#include <iostream>
#include "../NodeList/NodeList.h"
using namespace std;

int main()
{
//test 1:
//    NodeList zeft;
//    zeft.insertFront(1);
//    zeft.insertFront(2);
//    zeft.insertFront(3);
//    zeft.insertFront(4);
//    zeft.insertFront(5);
//    zeft.insertFront(6);
//    zeft.insertFront(7);
//    zeft.print();

//test 2:
    NodeList zeft;
    zeft.insertFront(1);
    zeft.insertFront(2);
    zeft.insertFront(3);
    zeft.insertFront(4);
    zeft.insertFront(5);
    zeft.insertFront(6);
    zeft.insertFront(7);
    zeft.print();
    cout<<endl;
    zeft.copy(zeft.get_iterator(4),zeft.get_iterator(6),zeft.get_iterator(0));
    zeft.print();


    return 0;
}
