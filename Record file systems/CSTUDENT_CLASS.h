#ifndef CSTUDENT_CLASS_H_INCLUDED
#define CSTUDENT_CLASS_H_INCLUDED

// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////
#include "RFS_CLASS.h"
class CStudent : public Record
{
    public:
        unsigned int m_Number;
        char m_Name [100];
        float m_SubjectGrade [10];
    public:
        CStudent();
        virtual ~CStudent();
};

#endif // CSTUDENT_CLASS_H_INCLUDED
