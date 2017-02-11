//StackFullException.hpp
//Derived class of StackException

#ifndef StackFullException_hpp  //To avoid multiple inclusion
#define StackFullException_hpp

#include "StackException.hpp"
#include <iostream>
#include <sstream>
using namespace std;	

class StackFullException : public StackException
{
private:
	int index;

public:
	// Constructors
	//StackFullException();										// Default constructor. As best practice we should have it. However, we are not constructing any objects without an input
	StackFullException(int i)										//Constructor with int as argument. To indicate the erroneous array index and store it in a data member. 
	{
		cout << "StackFullException constructor used" << endl;		//Default inline function
		index = i;
	}
	//virtual ~StackFull();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Position: " << index << " reached. Stack is full." << endl;
		return st.str();
	}

};
#endif

