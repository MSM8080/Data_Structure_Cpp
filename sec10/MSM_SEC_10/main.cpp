#include <iostream>
#include "ListPriorityQueue.h"
#include "process.h"
#include "vector2d.h"
#include <list>

using namespace std;

int main()
{

// No.2
//    ListPriorityQueue<int,AscendingOrder<int> > L1;
//    L1.insert(4);
//    L1.insert(1);
//    L1.insert(5);
//    L1.insert(0);
//    L1.insert(2);
//    L1.print();

// No.3
//    ListPriorityQueue<int,DescendingOrder<int> > L2;
//    L2.insert(4);
//    L2.insert(1);
//    L2.insert(5);
//    L2.insert(0);
//    L2.insert(2);
//    L2.print();

    Process processes[5]={
		Process("notepad.exe",10,3),
		Process("calc.exe",15,2),
		Process("winamp.exe",60,2),
		Process("explorer.exe",20,0),
		Process("word.exe",45,2)
	};
// No.4
//	ListPriorityQueue<Process,AscendingOrderProcessTime<Process> > L3;
//    for(int i=0;i<5;i++)
//    {
//        L3.insert(processes[i]);
//    }
//    L3.printProcess();

// No.5
//	ListPriorityQueue<Process,AscendingOrderProcessPrority<Process> > L4;
//    for(int i=0;i<5;i++)
//    {
//        L4.insert(processes[i]);
//    }
//    L4.printProcess();

// No.6
//	ListPriorityQueue<Process,AscendingOrderProcessProrityTime<Process> > L5;
//    for(int i=0;i<5;i++)
//    {
//        L5.insert(processes[i]);
//    }
//    L5.printProcess();

//No.7
    Point p;
	Vector2D dir;
	Point ps[100];

	srand(10000);
	// (Vector) Normal to the line
	dir.x_comp()=(float)rand();
	dir.y_comp()=(float)rand();
	dir.normalize();

	// Point on the line
	p.x=rand()/1000.0f;
	p.y=rand()/1000.0f;

	// Random points
	for(int i=0;i<100;i++)
	{
		ps[i].x=rand()/1000.0f;
		ps[i].y=rand()/1000.0f;
	}


//	Vector2D dir_crr;
//    dir_crr.x_comp()=ps[0].x;
//	dir_crr.y_comp()=ps[0].y;
//	dir_crr.normalize();
//cout<<"dist: "<<dir_crr.dotProduct(dir);

	ListPriorityQueue<Point,dist> L6;
    for(int i=0;i<100;i++)
    {
        L6.insert(ps[i]);
    }
    std::list<Point> lp = L6.ReturnSortedList();
    for (std::list<Point>::iterator i = lp.begin(); i != lp.end(); i++)
    {
        Point p =*i;
                Vector2D dir_p;
            dir_p.x_comp()=p.x;
            dir_p.y_comp()=p.y;
            dir_p.normalize();

        cout<<p.x<<"         "<<p.y<<"      "<<dir.dotProduct(dir_p);
        cout<<endl;
    }


	return 0;
}

