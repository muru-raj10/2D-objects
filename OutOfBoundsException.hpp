//OutofBoundsException.hpp
//Derived class of ArrayException

#ifndef OutOfBoundsException_hpp  //To avoid multiple inclusion
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>
using namespace std;	

class OutOfBoundsException : public ArrayException
{
private:
	int index;

public:
	// Constructors
	//OutOfBoundsException();										// Default constructor. As best practice we should have it. However, we are not constructing any objects without an input
	OutOfBoundsException(int i)										//Constructor with int as argument. To indicate the erroneous array index and store it in a data member. 
	{
		cout << "OutofBoundsException constructor used" << endl;	//Default inline function
		index = i;
	}
	//virtual ~OutOfBoundsException();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Position: " << index << " is out of bounds." << endl;
		return st.str();
	}

};
#endif

/*
inline string OutOfBoundsException::GetMessage() const				//Normal inline function and overrides GetMessage() from ArrayException
{
	stringstream st;
	st << "Position: " << index << " is out of bounds." << endl;
	return st.str();
}*/	