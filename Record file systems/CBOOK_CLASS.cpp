#include "CBOOK_CLASS.h"
#include <cstring>
// ----------------------------------------------------------
CBook::CBook()
{
    strcpy(b_Title,"");
    strcpy(b_Author,"");
    strcpy(b_Publisher,"");
    b_Number = 0;
    b_Number_of_pages = 0;
    b_Available_quantity = 0;
    b_Cost = 0;
}
// ----------------------------------------------------------
CBook::~CBook()
{

}
