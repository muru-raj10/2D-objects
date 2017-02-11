//StackException.hpp
//Base class. StackFull and StackEmpty exceptions are a derived class of this class.

#ifndef StackException_hpp  //To avoid multiple inclusion
#define StackException_hpp

#include <iostream>
#include <cmath>
#include <sstream> 
using namespace std;	

class StackException
{
private:

public:
	//Other member functions

	virtual string GetMessage() const=0;					//Get message function
};
#endif