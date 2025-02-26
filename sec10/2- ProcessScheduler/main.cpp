#include <iostream>
#include "Process.h"

using namespace std;

int main()
{
	Process processes[5]={
		Process("notepad.exe",10,3),
		Process("calc.exe",15,2),
		Process("winamp.exe",60,2),
		Process("explorer.exe",20,0),
		Process("word.exe",45,2)
	};
	return 0;
}

