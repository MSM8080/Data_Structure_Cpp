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

int linklist::find_data(int m_data, int& pos)
{
/*Enter you code here*/
/*test code: {0, -1, 1}*/

    if (first == NULL)
    {
        return -1;
    }

    link* current = first;
    int counter = 0;

    while(current != NULL)
    {
        if(m_data == current->data)
        {
            pos = counter;
            return 0;
        }
        current = current->next;
        counter++;
    }
    return -1;

/*End of your code*/
}

////////////////////////////////////////////////////////////////
int main()
{
        int data_len = rand()%151; //number of data items
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
    int pos;
    int data;
    int linklist_pos = -1;
    cout << "code: ";
    cin >> code;
    cout << endl;
    if (code == 0) // regular linklist
    {
        list<int> test_list (test_data, test_data+data_len);
        pos = rand()%data_len; // get a random position
        data = test_data[data_len-pos-1];
        code = li.find_data(data, linklist_pos); // returns 0
        if (!code && pos==linklist_pos)
            cout << "Test passed.";
        else
            cout << "Test failed.";
    }
    else if (code == -1)
    {
        list<int> test_list (test_data, test_data+data_len);
        pos = rand()%data_len+data_len; // get an invalid position
        code = li.find_data(pos, linklist_pos);
        if (!code) // should not return 0
        {
            cout << "Test failed.";
            return 0;
        }
        pos = -rand()%data_len-1; // get an invalid position
        code = li.find_data(pos, linklist_pos);
        if (!code) // should not return 0
        {
            cout << "Test failed.";
            return 0;
        }

        cout << "Test passed.";
    }
    return 0;
}
