#include "phonedirectory.h"
#include "../bst/binarysearchtree.h"
#include <list>
#include <queue>
#include <string>
#include <cstring>


void PhoneDirectory::insert(string name, string phone_num)
{
    Node* name_node;
    Node* phone_node;

    name_bst.add(name);
	name_node = name_bst.lastAdded();
	phone_bst.add(phone_num);
	phone_node = phone_bst.lastAdded();

	name_node->associated_node = phone_node;
	phone_node->associated_node = name_node;

}

void PhoneDirectory::remove(string name)
{
    Node* phone_node;
    name_bst.remove(name);
    phone_node = name_bst.lastRemoved();
    phone_bst.remove(phone_node->elt);
}

PositionList PhoneDirectory::search_by_name(string name)
{
    PositionList pl;
    if(name.length() == 3) // prefix name search
    {
        pl = name_bst.BinaryPrefixSearch(name);
        if(!pl.empty())
        {
            name_bst.InorderSearch(pl.front(),name,pl);
            pl.pop_front();
        }
        return pl;
    }
    else // full name search
    {
        pl = name_bst.BinarySearch(name);
        return pl;
    }
}

PositionList PhoneDirectory::search_by_phone_num(string phone_num)
{
    PositionList pl;
    if(phone_num.length() == 3) // prefix name search
    {
        pl = phone_bst.BinaryPrefixSearch(phone_num);
        if(!pl.empty())
        {
            phone_bst.InorderSearch(pl.front(),phone_num,pl);
            pl.pop_front();
        }
        return pl;
    }
    else // full name search
    {
        pl = phone_bst.BinarySearch(phone_num);
        return pl;
    }
}

PositionList PhoneDirectory::get_contact_list()
{
    PositionList pl;
	pl = name_bst.positions();
    return pl;
}

void PhoneDirectory::delete_all()
{
    PositionList names;
    names = get_contact_list();
    for (std::list<BinarySearchTree::Position>::iterator i = names.begin(); i != names.end(); i++)
    {
        PhoneDirectory::remove(**i); // remove name in name_bst
    }
}

unsigned int PhoneDirectory::get_count()
{
    cout<<"No.persons in directory: "<<name_bst.size()<<endl;
    return name_bst.size();
}
