#include <iostream>
#include "PD/phonedirectory.h"
#include "bst/binarysearchtree.h"
#include "pls/positionlistutils.h"
#include <string>
#include <strings.h>

using namespace std;

void PrintPositionList(PositionList& pl);

int main()
{
    PhoneDirectory phd;
    PositionList pl;
    PositionListUtils plu;

// --------------test 1-----------------//
//    phd.insert("jonathan sanchez","9792321");
//    phd.insert("wayne price","2852846");
//    phd.insert("jacqueline foster","8911705");
//    phd.insert("frances peterson","1225077");
//    phd.insert("ruth martin","5852057");
//    phd.insert("cheryl gonzales","1671333");
//    phd.insert("kelly simmons","4395869");
//    phd.insert("paula brooks","1425734");
//    phd.insert("andrew butler","3113081");
//    phd.insert("jack scott","1592468");
//
//    pl = phd.search_by_name("jack scott");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("cheryl gonzales");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("mike sanchez");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("jacqueline foster");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("wayne price");
//    plu.display_list(pl,true);

// --------------test 2-----------------//
//    phd.insert("jonathan sanchez","9792321");
//    phd.insert("wayne price","2852846");
//    phd.insert("jacqueline foster","8911705");
//    phd.insert("frances peterson","1225077");
//    phd.insert("ruth martin","5852057");
//    phd.insert("cheryl gonzales","1671333");
//    phd.insert("kelly simmons","4395869");
//    phd.insert("paula brooks","1425734");
//    phd.insert("andrew butler","3113081");
//    phd.insert("jack scott","1592468");
//
//    pl = phd.search_by_phone_num("2852846");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("1225077");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("1671335");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("4395869");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("1592468");
//    plu.display_list(pl,false);

// --------------test 3-----------------//
//    phd.insert("jonathan sanchez","9792321");
//    phd.insert("wayne price","2852846");
//    phd.insert("jacqueline foster","8911705");
//    phd.insert("frances peterson","1225077");
//    phd.insert("ruth martin","5852057");
//    phd.insert("cheryl gonzales","1671333");
//    phd.insert("kelly simmons","4395869");
//    phd.insert("paula brooks","1425734");
//    phd.insert("andrew butler","3113081");
//    phd.insert("jack scott","1592468");
//
//    phd.remove("jack scott");
//    phd.remove("cheryl gonzales");
//    phd.remove("mike sanchez");
//
//    pl = phd.search_by_name("jack scott");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("cheryl gonzales");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("jacqueline foster");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("wayne price");
//    plu.display_list(pl,true);

// --------------test 4-----------------//
//    phd.insert("jonathan sanchez","9792321");
//    phd.insert("wayne price","2852846");
//    phd.insert("jacqueline foster","8911705");
//    phd.insert("frances peterson","1225077");
//    phd.insert("ruth martin","5852057");
//    phd.insert("cheryl gonzales","1671333");
//    phd.insert("kelly simmons","4395869");
//    phd.insert("paula brooks","1425734");
//    phd.insert("andrew butler","3113081");
//    phd.insert("jack scott","1592468");
//
//    pl = phd.search_by_name("cheryl gonzales");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("kelly simmons");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_phone_num("9792321");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("2852846");
//    plu.display_list(pl,false);
//
//    phd.delete_all();
//
//    pl = phd.search_by_name("cheryl gonzales");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_name("kelly simmons");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_phone_num("9792321");
//    plu.display_list(pl,false);
//
//    pl = phd.search_by_phone_num("2852846");
//    plu.display_list(pl,false);

// --------------test 5-----------------//
//    phd.insert("ahmed mohamed","1359840");
//    phd.insert("ahmed ali","4029882");
//    phd.insert("ahmed mahmoud","2848213");
//    phd.insert("omar mohamed","3981230");
//    phd.insert("omar salah","3191922");
//    phd.insert("mostafa","3198229");
//
//    pl = phd.search_by_name("ahm");
//    plu.display_list(pl,true);
//
//    pl = phd.search_by_phone_num("319");
//    plu.sort_list(pl,false);
//    plu.display_list(pl,false);

    return 0;
}

//void PrintPositionList(PositionList& pl)
//{
//    if(pl.empty())
//    {
//        cout<<"{Not found !}"<<endl;
//        return;
//    }
//    else
//    {
//        cout<<"{found "<<pl.size()<<" matches}"<<endl;
//        for (std::list<BinarySearchTree::Position>::iterator i = pl.begin(); i != pl.end(); i++)
//        {
//            Position crr = *i;
//            cout <<" " << **i <<" , "<< !(crr);
//            cout<<endl;
//        }
//    }
//}
