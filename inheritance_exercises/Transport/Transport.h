#include<string>
#include<iostream>
using namespace std;

#ifndef Transport_Header
#define Transport_Header

class Transport
{
protected:
	int capacity;
	int passengers;
private:
	float  speed;
	string src;
	string dst;
public:
	Transport(string _src, string _dst,int _capacity, float _speed);
	string get_src();
	string get_dst();
	float get_speed();
	virtual bool has_available_space();
	virtual int book();
	virtual void print();
	float est_travel_time(float distance);
};

#endif