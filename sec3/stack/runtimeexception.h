#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H
#include <string>
using namespace std;

class RuntimeException { // generic run-time exception
	private:
		string error_msg;
	public:
		RuntimeException(const string& err)
		{
			error_msg = err;
		}
		string get_message() const
		{
			return error_msg;
		}
};
// -----------------------------------
class FullStackException : public RuntimeException
{
    FullStackException(const string& err)
    : RuntimeException(err) {}
};
// -----------------------------------
class EmptyStackException : public RuntimeException
{
    EmptyStackException(const string& err)
    : RuntimeException(err) {}
};
#endif
