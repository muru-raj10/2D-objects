// arrayclass.hpp
//
// Header file for array Template. To accomodate arrays of different objects with default size.


#ifndef ArrayTemplate_hpp  //To avoid multiple inclusion
#define ArrayTemplate_hpp

#include <iostream>
using namespace std;		

namespace Muru
{
	namespace Containers
	{

template <typename T>
class Array
{
private:		
		T* data;	
		int size;
		static int default_size;

public:
	// Constructors
	Array();										// Default constructor
	Array(const int& newsize);						// Constructor with size argument
	Array(const Array<T>& A); 							// Copy constructor
	virtual ~Array();								// Destructor

	// Member operator overloading
	Array<T>& operator = (const Array<T>& Arr);			// Assignment operator	

	// Accesssing functions
	virtual T& GetElement(int position) const;						// Getter for the array elements. Change to default virtual

	// Modifiers
	virtual void SetElement(int position, const T& pt);				//  Setter for the array element. Change to default virtual

	//Other member functions

	virtual int Size() const;								// size function to get the size of the array
	
	static int DefaultSize();						//Getter function for getting the default size. Static member function cannot be const function as it has no access to member variables.

	static int DefaultSize(int newdefaultsize);		//Setter function to set new default size

	T& operator [] (int index);						// square bracket operator

	const T& operator [] (int index) const;
};
	}
}

#ifndef ArrayTemplate_cpp		// By these statements, we include the cpp file within this header file. And thus, the definitions of the functions. Ifndef handles multiple inclusions.
#include "ArrayTemplate.cpp"	// Hence, in the test program, we only need to include this header file.
#endif							// Functions in template are usually declared and defined in the same file and sometimes it is called .tpp, 
								// However, it is not ideal for code readability and code hiding. 
#endif