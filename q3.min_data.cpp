#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

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

int linklist::min_data(int& m_data)
{
/*Enter you code here*/
/*test code: {0, -1}*/

if(first==NULL)
{
    return -1;
}

link *current = first;
m_data = current->data;

while(current!=NULL)
{
    if(current->data < m_data)
    {
        m_data = current->data;
    }
    current = current->next;
}

return 0;

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
    if (code == 0)
    {
        if(!li.min_data(data) &&
           data == *min_element(test_data, test_data+data_len)) // correct return and data
            cout << "Test passed." << endl;
        else
            cout << "Test failed." << endl;
    }
    else if (code == -1) // Empty list
    {
        linklist li_empty;
        if(li_empty.min_data(data)) // correct return
            cout << "Test passed." << endl;
        else
            cout << "Test failed." << endl;
    }
    return 0;
}
