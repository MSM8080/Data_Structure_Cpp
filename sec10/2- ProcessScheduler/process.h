#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process{
    private:
        string name;
        float executionTime;
        int priority;
    public:
        Process();
        Process(string _name, float _executionTime, int _priority);
        void print();
        float getExecutionTime() const;
        int getPriority() const;
};

#endif // PROCESS_H
