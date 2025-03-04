// RFS.cpp: implementation of the RFS class.
//
//////////////////////////////////////////////////////////////////////
#include "RFS_CLASS.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
RFS::~RFS()
{
    F.close();
}
//////////////////////////////////////////////////////////////////
RFS::RFS(int sor,char filename[])
{
    numberOfRecords=0;
    sizeOfRecord=sor;
    F.open(filename,ios::app|ios::out|ios::in|ios::binary);
    F.close(); // to create it if not exist
    // a bug in c++
    F.open(filename,ios::out|ios::in|ios::binary);
    if(good())
    {
        cout<< filename<<" is Open"<<endl;
        F.seekg(0,ios::end);
        numberOfRecords=F.tellg()/sizeOfRecord;
    }
    else
    {
        cout<< "could not open"<<filename<<endl;
    }
}
/////////////////////////////////////////////
bool RFS::get(Record * r,uint i)
{
    if (!good())
    {
        cout<< "error reading from file"<<endl;
        return false;
    }
    if (i<numberOfRecords)
    {
        F.seekg(recodLocation(i),ios::beg);
        F.read((char *)r,sizeOfRecord);
        return true;
    }
    else
        return false;
}
/////////////////////////////////////////////
bool RFS::put(Record * r,uint i)
{
    if (!good())
    {
        cout<< "error writting to file"<<endl;
        return false;
    }
    if (i==-1)
    { //append
        r->active=true;
        r->RecordNumber=numberOfRecords;
        F.seekg(recodLocation(numberOfRecords),ios::beg);
        F.write((char *)r,sizeOfRecord);
        numberOfRecords++;
        return true;
    }
    else
        if (i<numberOfRecords)
        {
            r->RecordNumber=i;
            F.seekg(recodLocation(i),ios::beg);
            F.write((char *)r,sizeOfRecord);
            return true;
        }
    else
        return false;
}
/////////////////////////////////////////////
bool RFS::del(Record * r)
{
    r->active=false;
    return(put(r,r->RecordNumber));
}
/////////////////////////////////////////////
bool RFS::update(Record * r)
{
    return(put(r,r->RecordNumber));
}
/////////////////////////////////////////////
bool RFS::good()
{
    return F.good();
}
