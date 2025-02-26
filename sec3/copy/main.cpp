#include<iostream>
#include"array.h"
using namespace std;

int main()
{
	int arr[15];
	for(int i=0;i<15;i++)
	{
		arr[i]=i*2+1;
	}
	print(arr,15);
	cout<<"copying 5 items from index 0 to 3"<<endl;
	copy(arr,15,0,3,5);
	print(arr,15);
	cout<<"copying 5 items from index 7 to 5"<<endl;
	copy(arr,15,7,5,5);
	print(arr,15);
	return 0;
}