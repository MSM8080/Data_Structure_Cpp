#include "Transport.h"

// complete the constructor to initialize the private data
Transport::Transport(string _src, string _dst, int _capacity, float _speed)
 : src(_src) , dst(_dst) , capacity(_capacity) , speed(_speed)
{}

string Transport::get_src()
{
	return src;
}

string Transport::get_dst()
{
	return dst;
}

float Transport::get_speed()
{
	return speed;
}

// complete the function to return true if there is available ticket for booking
bool Transport::has_available_space()
{
    return (if(capacity>passengers));
}

// attempt to book a ticket and return its index
// return -1 if the booking attempt fails
int Transport::book()
{

}

// print all the transport information
void Transport::print()
{

}

// function returns travel time estimate
float Transport::est_travel_time(float distance)
{

}

