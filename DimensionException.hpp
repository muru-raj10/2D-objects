//DimensionException.hpp
//Derived class of ArrayException
//To indicate when certain operations are not possible because of different dimensions

#ifndef DimensionException_hpp  //To avoid multiple inclusion
#define DimensionException_hpp

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>
using namespace std;	

class DimensionException : public ArrayException
{
private:
	

public:
	// Constructors
	DimensionException()										//Default Constructor
	{
		cout << "DimensionException constructor used" << endl;	//Default inline function
	
	}
	//virtual ~OutOfBoundsException();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Dimension mismatch. Operation failed" << endl;
		return st.str();
	}

};
#endif
