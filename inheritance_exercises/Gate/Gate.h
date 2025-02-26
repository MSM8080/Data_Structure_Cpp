#include <iostream>
using namespace std;

#ifndef Gate_Header
#define Gate_Header

// A gate in a digital ciruit
class Gate
{
	private:
		bool * input;    // points to an array that holds the input values of the Gate
		int n;    		 // # Gate inputs
	public:
		Gate(int noi);
		void setInput(int ind,bool value);
		bool getInput(int ind);
		int getNumberOfInputs();
};

#endif
