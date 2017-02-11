//DimensionInappropriate.hpp
//Derived class of ArrayException
//To indicate when certain operations are not possible because of insufficient dimensions

#ifndef DimensionInappropriate_hpp  //To avoid multiple inclusion
#define DimensionInappropriate_hpp

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>
using namespace std;	

class DimensionInappropriate : public ArrayException
{
private:
	

public:
	// Constructors
	DimensionInappropriate()										//Default Constructor
	{
		cout << "DimensionInappropriate constructor used" << endl;	//Default inline function
	
	}
	//virtual ~OutOfBoundsException();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Dimension Inappropriate. Operation failed" << endl;
		return st.str();
	}

};
#endif
