// sheet5.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//#define question1
//#define question2
#define question3
//#define question4
//you have to implement 5 in your own function
// #define question6

#ifdef question1
void rec_dec2bin_disp(unsigned int dec_num)  // dec_num --> display binary_num
{
    //string s;
        if(dec_num==0)
            return;
       else if(dec_num%2 == 0)
         {
                rec_dec2bin_disp(dec_num/2);
             cout<<"0";
                //s = s+ '0';

         }
        else if( dec_num%2 != 0)
         {
                rec_dec2bin_disp((dec_num-1)/2);

             cout<<"1";
                //s = s+'1' ;
         }
}
#endif // question1

#ifdef question2
string rec_dec2bin_str(unsigned int dec_num) // dec_num --> binary string
{
        string s;
        if(dec_num==0)
            return s;
        else if(dec_num%2 ==0)
            s = rec_dec2bin_str(dec_num/2) + '0';
        else if(dec_num%2 !=0)
            s = rec_dec2bin_str((dec_num-1)/2) + '1';
        //s.erase(0,0);
        return s;
}
#endif // question2

#ifdef question3
float rec_pow(float x,int n)   //x^(2^n)
{
if(n==0) return x;
if(n==1) return x*x;
return rec_pow(x*x,n-1);
}
#endif // question3

#ifdef question4
int rec_log2(int n)   // rec_log2(n)
{}
#endif // question4

#ifdef question6
void gray(string sts[],int bits)
{}
#endif // question6

int main()
{
#ifdef question1
	cout << "question 1";
	cout << "\nExpexted output is: 1100100\n";
	cout << "your output is    : ";
	rec_dec2bin_disp(100);
	cout << "\n\nExpexted output is: 1010\n";
	cout << "your output is    : ";
	rec_dec2bin_disp(10);
	cout << "\n\nExpexted output is: 1\n";
	cout << "your output is    : ";
	rec_dec2bin_disp(1);
#endif
#ifdef question2
	cout << "\n\nquestion 2";
	cout << "\nExpexted output is : 1100100\n";
	string s = rec_dec2bin_str(100);
	cout << "your output is     : " << s << endl;

	cout << "\nExpexted output is : 1010\n";
	s = rec_dec2bin_str(10);
	cout << "your output is     : " << s << endl;

	cout << "\nExpexted output is : 1\n";
	s = rec_dec2bin_str(1);
	cout << "your output is     : " << s << endl;
#endif
#ifdef question3
	cout << "\n\nquestion 3";
	cout << "\nExpexted output is : 2.32831e+06\n";
	float f = rec_pow(2.5,4);
	cout << "your output is     : " << f << endl;
#endif
#ifdef question4
	cout << "\n\nquestion 4";
	cout << "\nExpexted output is : 6\n";
	int s2 = rec_log2(100);
	cout << "your output is     : " << s2 << endl;

	cout << "\nExpexted output is : 3\n";
	s2 = rec_log2(10);
	cout << "your output is     : " << s2 << endl;

	cout << "\nExpexted output is : 0\n";
	s2 = rec_log2(1);
	cout << "your output is     : " << s2 << endl;

	cout << "\nExpexted output is : 0\n";
	s2 = rec_log2(0);
	cout << "your output is     : " << s2 << endl;
#endif
#ifdef question6
    string grays1[2];
	cout << "\n\nquestion 6";
	cout << "\nExpexted output is :  0 1\n";
	cout << "your output is     : ";
	gray(grays1, 1);
	for (int i = 0; i < 2; i++)
		cout << setw(2)<<grays1[i];
	cout << endl;
    string grays2[4];
	cout << "\nExpexted output is :  00 01 11 10\n";
	cout << "your output is     : ";
	gray(grays2, 2);
	for (int i = 0; i < 4; i++)
		cout << setw(3) << grays2[i];
	cout << endl;
    string grays3[8];
	cout << "\nExpexted output is :  000 001 011 010 110 111 101 100\n";
	cout << "your output is     : ";
	gray(grays3, 3);
	for (int i = 0; i < 8; i++)
		cout << setw(4) << grays3[i];
	cout << endl;
    string grays4[16];
	cout << "\nExpexted output is :  0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000\n";
	cout << "your output is     : ";
	gray(grays4, 4);
	for (int i = 0; i < 16; i++)
		cout << setw(5) << grays4[i];
	cout << endl;
#endif
    return 0;
}

