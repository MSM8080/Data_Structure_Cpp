#ifndef CLIBRARY_CLASS_H_INCLUDED
#define CLIBRARY_CLASS_H_INCLUDED

#include "RFS_CLASS.h"
class CLibrary
{
    private:
        RFS rfs;
    public:
        CLibrary(char filename[]);
        bool AddNewBook();
        bool SearchForBookByTitle();
        bool FindBookByAuthor();
        bool FindBookByPublisher();
        bool ChangeBookCost();
        bool ChangeBookQuantity();
        bool DeleteBook();
        bool SortBooksTitle();
        bool FindBookZeroQuantity();
        bool FindBookExpensiveCost();
};


#endif // CLIBRARY_CLASS_H_INCLUDED
