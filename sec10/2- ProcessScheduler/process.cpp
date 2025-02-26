#include "process.h"

Process::Process(){}

Process::Process(string _name,float _executionTime,int _priority):
    name(_name),executionTime(_executionTime),priority(_priority)
{}

void Process::print()
{
    cout<<"Process:"<<name<<endl
        <<"\tExpected Execution Time: "<<executionTime<<endl
        <<"\tPriority: "<<priority<<endl;
}

float Process::getExecutionTime() const
{   return executionTime;   }

int Process::getPriority() const
{   return priority;    }
