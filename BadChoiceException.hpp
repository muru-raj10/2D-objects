//BadChoiceException.hpp

#ifndef BadChoiceException_hpp  //To avoid multiple inclusion
#define BadChoiceException_hpp


#include <iostream>
#include <sstream>
using namespace std;	

class BadChoiceException 
{
private:

public:
	// Constructors
	// Default constructor. 

	//virtual ~OutOfBoundsException();								// Destructor. As best practice, we should have it. However, the system generated destructor works fine here.

	//Other member functions

	string GetMessage() const										//Get message function
	{
		stringstream st;
		st << "Invalid Choice" << endl;
		return st.str();
	}

};
#endif
