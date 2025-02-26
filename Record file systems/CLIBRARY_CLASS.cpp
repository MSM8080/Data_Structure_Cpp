#include "CLIBRARY_CLASS.h"
#include "CBOOK_CLASS.h"
#include "RFS_CLASS.h"
#include <cstring>
// --------------------------------------------------
CLibrary::CLibrary(char filename[])
: rfs(sizeof(CBook),filename)
{ }
// --------------------------------------------------
bool CLibrary::AddNewBook()
{
    CBook NewBook;

    cout<<"\t\t\tAdding New Book\n\n";
    cout<<"Book Number : ";
    cin>>NewBook.b_Number;
    cin.ignore(); // to avoid bug in getline

    cout<<"Book Title : ";
    cin.getline(NewBook.b_Title,100);

    cout<<"Book Author : ";
    cin.getline(NewBook.b_Author,100);

    cout<<"Book Publisher : ";
    cin.getline(NewBook.b_Publisher,100);

    cout<<"Book Available quantity : ";
    cin>>NewBook.b_Available_quantity;
    cin.ignore(); // to avoid bug in getline

    cout<<"Book Number of pages : ";
    cin>>NewBook.b_Number_of_pages;
    cin.ignore(); // to avoid bug in getline

    cout<<"Book Cost : ";
    cin>>NewBook.b_Cost;
    cin.ignore(); // to avoid bug in getline

    return(rfs.put(&NewBook));
}
// --------------------------------------------------
//
//        bool SearchForBookByTitle();
//// --------------------------------------------------
//
//        bool FindBookByAuthor();
//// --------------------------------------------------
//
//        bool FindBookByPublisher();
//// --------------------------------------------------
//
//        bool ChangeBookCost();
//// --------------------------------------------------
//
//        bool ChangeBookQuantity();
//// --------------------------------------------------
//
//        bool DeleteBook();
//// --------------------------------------------------
//
//        bool SortBooksTitle();
//// --------------------------------------------------
//
//        bool FindBookZeroQuantity();
//// --------------------------------------------------
//
//        bool FindBookExpensiveCost();
//// --------------------------------------------------
//
//        bool SortBooksTitle();
