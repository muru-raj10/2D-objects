//StackEmptyException.hpp
//Derived class of StackException

#ifndef StackEmptyException_hpp  //To avoid multiple inclusion
#define StackEmptyException_hpp

#include "StackException.hpp"
#include <iostream>
#include <sstream>
using namespace std;	

class StackEmptyException : public StackException
{
private:
	

public:
	// Constructors
	StackEmptyException()										// Default constructor.
	{
		cout << "StackEmptyException constructor used" << endl;		//Default inline function
	}
	//virtual ~OutOfBoundsException();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Stack is already Empty." << endl;
		return st.str();
	}

};
#endif

