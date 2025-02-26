#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stack>
using namespace std;
using std::stack;
#define stack_ex_1
//#define stack_ex_2
#define stack_ex_3
#define stack_ex_4
#define stack_ex_5
#define stack_ex_6
#ifdef stack_ex_1
template <typename T>
void print(stack<T> & s)
{
    if(s.empty()==1)
        return;
    else
    {
        T elem = s.top();
        cout<<s.top()<<" ";
        s.pop();
        print(s);
        s.push(elem);
        return;
    }
}
#endif
#ifdef stack_ex_2
bool is_valid(string st)
{
	//add your code here
}
#endif
#ifdef stack_ex_3
template <typename T>
stack<T> copy_stack(stack<T> & s)
{
    stack<T>  c;
    c = s;
    return c;
}
#endif
#ifdef stack_ex_4
template <typename T>
stack<T> reverse_stack(stack<T> & s)
{
    stack<T> c=s;
    stack<T> r;

    while(c.empty()!=1)
    {
        r.push(c.top());
        c.pop();
    }
    return r;
}
#endif
#ifdef stack_ex_5
template <typename T>
void remove_all_elements(stack<T> & s)
{
    if(s.empty()==1)
        return;
    else
    {
        s.pop();
        remove_all_elements(s);
        return;
    }
}
#endif
#ifdef stack_ex_6
template <typename T>
void remove_element(stack<T> & s,int ind)
{
    if(ind>s.size())
        return;
    else if(ind==0)
    {
        s.pop();
        return;
    }
    else
    {
        T elem = s.top();
        s.pop();
        remove_element(s,ind-1);
        s.push(elem);
        return;
    }
}
#endif
int main()
{
	stack<int> st;
	stack<int> st2;
	srand(3);
	for (int i = 0; i < 5; i++)
	{
		st.push(rand() % 100);
	}
#ifdef stack_ex_1
	cout << "\ntesting stack ex 1\n";
	cout << "Expected output is : 31,91,94,96,48\n";
	cout << "your output is     : ";
	print(st);
	cout << "\nExpected output is : 31,91,94,96,48\n";
	cout << "your output is     : ";
	print(st);
	cout << "\nExpected output is : \n";
	cout << "your output is     : ";
	print(st2);
	cout << "\n\n\n";
#endif
#ifdef stack_ex_2
	cout << "\ntesting stack ex 2";
	cout << "\ntesting for string (4+d)";
	cout << "\nExpected output is : 1\n";
	cout << "your output is     : "<< is_valid("(4+d)");
	cout << "\ntesting for string (4+d[4+3])";
	cout << "\nExpected output is : 1\n";
	cout << "your output is     : " << is_valid("(4+d[4+3])");
	cout << "\ntesting for string (4+d[4+3]";
	cout << "\nExpected output is : 0\n";
	cout << "your output is     : " << is_valid("(4+d[4+3]");
	cout << "\ntesting for string (4+d[4+{3}]<4>)";
	cout << "\nExpected output is : 1\n";
	cout << "your output is     : " << is_valid("(4+d[4+{3}]<4>)");
	cout << "\ntesting for string (4+d[4+{3]}<4>)";
	cout << "\nExpected output is : 0\n";
	cout << "your output is     : " << is_valid("(4+d[4+{3]}<4>)");
	cout << "\n\n\n";
#endif
#ifdef stack_ex_3
	cout << "\ntesting stack ex 3\n";
	cout << "Expected output is : 31,91,94,96,48\n";
	stack<int> s2 = copy_stack(st);
	cout << "your output is     : ";
	print(s2);
	cout << "\nExpected output is : \n";
	stack<int> s3 = copy_stack(st2);
	cout << "your output is     : ";
	print(s3);
	cout << "\n\n\n";
#endif
#ifdef stack_ex_4
	cout << "\ntesting stack ex 4\n";
	cout << "Expected output is : 48,96,94,91,31\n";
	stack<int> s4 = reverse_stack(st);
	cout << "your output is     : ";
	print(s4);
	cout << "\nExpected output is : 48,96,94,91,31\n";
	stack<int> s5 = reverse_stack(st);
	cout << "your output is     : ";
	print(s5);
	cout << "\nExpected output is : \n";
	stack<int> s6 = reverse_stack(st2);
	cout << "your output is     : ";
	print(s6);
	cout << "\n\n\n";
#endif
#ifdef stack_ex_5
	cout << "\ntesting stack ex 5\n";
	cout << "Expected output is : \n";
	stack<int> s7 = copy_stack(st);
	remove_all_elements(s7);
	cout << "your output is     : ";
	print(s7);
	cout << "\nExpected output is : \n";
	stack<int> s8 = copy_stack(st2);
	remove_all_elements(s8);
	cout << "your output is     : ";
	print(s8);
	cout << "\n\n\n";
#endif
#ifdef stack_ex_6
	cout << "\ntesting stack ex 6\n";
	cout << "Expected output is : 31,94,96,48\n";
	stack<int> s9 = copy_stack(st);
	remove_element(s9, 1);
	cout << "your output is     : ";
	print(s9);
	cout << "\nExpected output is : 31,91,94,48\n";
	stack<int> s10 = copy_stack(st);
	remove_element(s10, 3);
	cout << "your output is     : ";
	print(s10);
	cout << "\nExpected output is : 31,91,94,96,48\n";
	stack<int> s11 = copy_stack(st);
	remove_element(s11, 7);
	cout << "your output is     : ";
	print(s11);
#endif
	cout << endl;
	return 0;
}
