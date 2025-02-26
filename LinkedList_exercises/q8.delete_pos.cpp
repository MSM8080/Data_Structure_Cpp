#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

////////////////////////////////////////////////////////////////
struct link //one element of list
{
    int data; //data item
    link* next; //pointer to next link
};
////////////////////////////////////////////////////////////////

class linklist //a list of links
{
private:
    link* first; //pointer to first link
public:
    linklist() //no-argument constructor
        { first = NULL; } //no first link
    void additem(int d); //add data item (one link)
    void display(); //display all links
    // Assignment
    int get_at(int pos, int &m_data);
    int max_data(int& m_data);
    int min_data(int& m_data);
    void add_last(int m_data);
    int delete_first();
    int delete_last();
    int add_pos(int pos, int m_data);
    int delete_pos(int pos);
    int find_data(int m_data, int& pos);
    void sort_list();
};

//--------------------------------------------------------------
void linklist::additem(int d) //add data item
{
    link* newlink = new link; //make a new link
    newlink->data = d; //give it data
    newlink->next = first; //it points to next link
    first = newlink; //now first points to this
}
//--------------------------------------------------------------
void linklist::display() //display all links
{
    link* current = first; //set ptr to first link
    while( current != NULL ) //quit on last link
    {
        cout << current->data << endl; //print data
        current = current->next; //move to next link
    }
}
//--------------------------------------------------------------

int linklist::delete_pos(int pos)
{
/*Enter you code here*/
/*test code: {0, -1, 1}*/

    if ((pos<0) || (first == NULL))
    {
        return -1;
    }
    else if (first->next == NULL)
    {
        first = NULL;
        return 0;
    }
    else
    {
        link* previous = first;
        link* current = first->next;
        int counter = 1;

        while(current!= NULL)
        {
            if(pos==counter)
            {
                previous->next = current->next;
                current = NULL;
                return 0;
            }
            current = current->next;
            previous = previous->next;
            counter++;
        }
    }
    return -1;

/*End of your code*/
}


////////////////////////////////////////////////////////////////
int main()
{
    int data_len = 4; //number of data items
    int max_data = 1000;
    const int data_m = max_data/2;
    int *test_data = new int[data_len];
    srand(time(NULL)); //seed
    for (int i=0; i<data_len; i++)
        (test_data[i] = rand()%max_data-data_m);

    linklist li; //make linked list
    for (int i=0; i<data_len; i++) // add for items to list
        li.additem(test_data[i]);
    //li.display();
    // test int get_at(int pos, int m_data)
    int code;
    int pos;
    int data = -1;
    cout << "code: ";
    cin >> code;
    cout << endl;
    // Redirecting cout stream
    stringstream redirect_stream;
    string linklist_string, test_string;
    streambuf *coutbuf = std::cout.rdbuf(); // original buffer
    cout.rdbuf(redirect_stream.rdbuf()); // redirect buffer

    if (code == 0) // regular linklist
    {
        pos = rand() % data_len;
        code = li.delete_pos(pos);
        if(code) // function should return 0
        {
            cout.rdbuf(coutbuf); // restore original buffer
            cout << "Test failed.";
            return 0;
        }
        list<int> test_list (test_data, test_data+data_len);
        list<int>::iterator it = test_list.begin();
        advance(it, data_len-pos-1); // move to a position in list
        test_list.erase(it); // erase data item in test_list
        li.display(); // linkedlist data
        linklist_string = redirect_stream.str(); // get linklist data
        redirect_stream.str(""); // clear stream

        for (list<int>::reverse_iterator rev_it=test_list.rbegin();
             rev_it!=test_list.rend(); rev_it++)
            redirect_stream << *rev_it << endl;

        test_string = redirect_stream.str(); // get test data
        redirect_stream.str(""); // clear stream
        cout.rdbuf(coutbuf); // restore original buffer
        if (test_string == linklist_string)
            cout << "Test passed.";
        else
            cout << "Test failed.";
    }
    else if (code == -1) // Empty list
    {
        linklist li_empty;
        pos = rand()%1;
        data = rand()%max_data;
        li_empty.additem(data); // insert item
        code = li_empty.delete_pos(pos);
        if(code) // function should return 0
        {
            cout.rdbuf(coutbuf); // restore original buffer
            cout << "Test failed.";
            return 0;
        }
        li_empty.display();
        linklist_string = redirect_stream.str(); // get linklist data
        redirect_stream.str(""); // clear stream
        test_string = redirect_stream.str(); // get test data
        cout.rdbuf(coutbuf); // restore original buffer
        if (test_string == linklist_string)
            cout << "Test passed.";
        else
            cout << "Test failed.";
    }
    else if (code == 1)
    {
        linklist li_empty;
        pos = rand()%max_data;
        code = li_empty.delete_pos(pos);
        if(!code) // function should return -1
        {
            cout.rdbuf(coutbuf); // restore original buffer
            cout << "Test failed.";
            return 0;
        }
        pos = -rand()%max_data-1;
        code = li_empty.delete_pos(pos);
        if(!code) // function should return -1
        {
            cout.rdbuf(coutbuf); // restore original buffer
            cout << "Test failed.";
            return 0;
        }
        cout.rdbuf(coutbuf); // restore original buffer
        cout << "Test passed.";
    }

    return 0;
}
