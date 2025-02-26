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

void linklist::sort_list()
{
/*Enter you code here*/

/*test code: {0, -1}*/

/*End of your code*/
}

////////////////////////////////////////////////////////////////
bool desc_comp( const int& first, const int& second )
{ return first > second ; }
////////////////////////////////////////////////////////////////

int main()
{
    int data_len = 100; //number of data items
    int max_data = 1000;
    const int data_m = max_data/2;
    int *test_data = new int[data_len];
    srand(time(NULL)); //seed
    for (int i=0; i<data_len; i++)
        (test_data[i] = rand()%max_data-data_m);

    linklist li; //make linked list
    for (int i=0; i<data_len; i++) // add for items to list
        li.additem(test_data[i]);
    int code = -1;
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
        list<int> test_list (test_data, test_data+data_len);
        test_list.sort(desc_comp); // sort test_list descendingly
        li.sort_list(); // sort linked list ascendingly
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
        li_empty.sort_list();
        cout.rdbuf(coutbuf); // restore original buffer
        cout << "Test passed.";
    }

    return 0;
}