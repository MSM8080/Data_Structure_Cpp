#ifndef CSCHOOL_CLASS_H_INCLUDED
#define CSCHOOL_CLASS_H_INCLUDED

// School.h: interface for the CSchool class.
//
//////////////////////////////////////////////////////////////////////
#include "RFS_CLASS.h"
class CSchool
{
    private:
        RFS rfs;
    public:
        CSchool(char filename[]);
        bool AddNewStudent();
        bool RemoveStudent();
        bool ModifyStudent();
        bool SearchForStudent();
        bool Sort();
};

#endif // CSCHOOL_CLASS_H_INCLUDED
