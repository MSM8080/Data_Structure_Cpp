#ifndef RECORD_CLASS_H_INCLUDED
#define RECORD_CLASS_H_INCLUDED

// Record.h: interface for the Record class.
//
//////////////////////////////////////////////////////////////////////
typedef unsigned int uint;
class RFS;
class Record
{
    protected:
        uint RecordNumber;
        bool active;
        friend class RFS;
    public:
        Record();
        virtual ~Record();
        bool isActive() {return active;}
};

#endif // RECORD_CLASS_H_INCLUDED
