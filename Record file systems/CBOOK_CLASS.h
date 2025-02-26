#ifndef CBOOK_CLASS_H_INCLUDED
#define CBOOK_CLASS_H_INCLUDED

#include "RFS_CLASS.h"
class CBook : public Record
{
    public:
        unsigned int b_Number;
        unsigned int b_Available_quantity;
        unsigned int b_Number_of_pages;
        unsigned int b_Cost;

        char b_Title [100];
        char b_Author [100];
        char b_Publisher [100];

    public:
        CBook();
        virtual ~CBook();
};


#endif // CBOOK_CLASS_H_INCLUDED
