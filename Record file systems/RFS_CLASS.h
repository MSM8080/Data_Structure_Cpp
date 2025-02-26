#ifndef RFS_CLASS_H_INCLUDED
#define RFS_CLASS_H_INCLUDED

// RFS.h: interface for the RFS class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "RECORD_CLASS.h"
using namespace std;
typedef unsigned int uint;
class RFS
{
    protected:
        uint numberOfRecords;
        uint sizeOfRecord;
        fstream F;
        uint recodLocation(uint i) {return (i*sizeOfRecord);}
    public:
        RFS(int sor,char filename[]);
        bool get(Record * r, uint i);
        bool put(Record * r, uint i=-1); // single input= append;
        bool update(Record * r);
        bool del(Record * r);
        bool good();
        uint GetNumberOfRecords() {return numberOfRecords;}
        virtual ~RFS();
};
#endif // RFS_CLASS_H_INCLUDED
