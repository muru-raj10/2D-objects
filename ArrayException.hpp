//ArrayException.hpp
//Basic class. OutofBoundsException is a derived class of this class.

#ifndef ArrayException_hpp  //To avoid multiple inclusion
#define ArrayException_hpp

#include <iostream>
#include <cmath>
#include <sstream> 
using namespace std;	

class ArrayException
{
private:

public:
	//Other member functions

	virtual string GetMessage() const=0;					//Get message function
};
#endif