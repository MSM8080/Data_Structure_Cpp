#include <iostream>
#include "stack.h"
using namespace std;
#define testcase0
//#define testcase1
int main()
{
    try{
    Stack<int> s1;
	s1.push(11);
	s1.push(22);
	cout << "1: " << s1.pop() << endl; //22
	cout << "2: " << s1.pop() << endl; //11
	#ifdef testcase0
	#ifndef testcase1
	cout << "2: " << s1.pop() << endl; //11
	#endif // testcase1
	#endif // testcase0
	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);
	s1.push(55);
	s1.push(66);
	s1.push(77);
	s1.push(88);
	s1.push(99);
	#ifdef testcase1
	s1.push(100);
	s1.push(110);
	#endif // testcase1


	}

	catch (EmptyStackException &a){
	    cout<<a.get_message();
    }
    catch (FullStackException &a){
        cout<<a.get_message();
    }
    return 0;
}
