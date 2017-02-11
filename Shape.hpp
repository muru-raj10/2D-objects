// Shape.hpp
//
// Header file for Shape class. 
//Add draw function. Add print function

#ifndef Shape_hpp  //To avoid multiple inclusion
#define Shape_hpp

#include <iostream>
#include "stdlib.h";
using namespace std;

class Shape
{
private:
	int id;			// 

public:
	// Constructors
	Shape();				// Default constructor
	Shape(const Shape& sh);	//Copy constructor
	virtual ~Shape();		// destructor	

	// Member operator overloading
	Shape& operator = (const Shape& source); // Assignment operator. 
	
	// Accessing functions(selectors)
	int ID() const;						//To retrieve the id of shape

	//Other member functions
	virtual string ToString() const;				// To print id as a string. Make it a virtual function
	virtual void Draw() const=0;					//Draw function. Virtual allows the function to be overridden in derived classes.
	void Print() const;								//Print function is a base class function
};


#endif