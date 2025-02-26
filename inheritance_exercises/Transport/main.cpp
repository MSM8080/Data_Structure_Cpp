#include "Transport.h"
#include "Taxi.h"
#include "Ship.h"
#include "Bus.h"
#include "get_fastest.h"

// #define TestCase0

int main()
{
    int ind = 0;
	Transport* t[7];
	t[0]=  new Taxi("Assiut","Minia",20,"Hassneen");
	t[1]=  new Taxi("Assiut","Minia",25,"Rageb");
	t[2]=  new Ship("Egypt","Italy");
	t[3]=  new Ship("Italy","Egypt");
	t[4]=  new Bus("Assiut","Cairo",1,"ahmed");
	t[5]=  new Bus("Cairo","Assiut",2,"mohamed");
	t[6]=  new Bus("Cairo","Assiut",2,"mohamed");
	//////////////////////////////////////////////////////////

#ifdef TestCase0
    for (int i=0;i<4; i++){
        ind=get_fastest(t, 7, "Assiut", "Minia");
        if( (ind!=-1)&& (t[ind]->has_available_space()) ){
            t[ind]->book();
            cout<<"Passenger: "<<i<<endl;
            t[ind]->print();
            cout<<endl;
        }
    }
    ind=get_fastest(t, 7, "Egypt", "Italy");
    if((ind!=-1)&& (t[ind]->has_available_space()) ){
        t[ind]->book();
        t[ind]->print();
        cout<<endl;
    }

    ind=get_fastest(t, 7, "Italy", "Istanbul");
    if( (ind!=-1)&& (t[ind]->has_available_space()) ){
        t[ind]->book();
        t[ind]->print();
        cout<<endl;
    }

    bool ttc=true;
    for (int i=0; i<4; i++)
    {
        ind=get_fastest(t, 7, "Assiut", "Minia");
        if(ind!=-1){
            t[ind]->book();
        }
        else{
            ttc=false;
            break;
        }
    }
    ind=get_fastest(t, 7, "Assiut", "Minia");
    ttc = ind==-1? true:false;

    cout<<"TestCase0: ";
    if(ttc)
        cout<<"passed";
    else
        cout<<"failed";
	return 0;
#endif // TestCase0
}

