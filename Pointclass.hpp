// Pointclass.hpp
//
// Header file for Points in two dimensions and their functions with operator overloading
// derived class of shape. Add in the draw function

#ifndef Pointclass_hpp  //To avoid multiple inclusion
#define Pointclass_hpp

#include <iostream>
#include "Shape.hpp"
using namespace std;

namespace Muru
{
	namespace CAD
	{

class Point : public Shape
{
private:
	double x;	// X coordinate
	double y;	// Y coordinate

public:
	// Constructors
	Point();	// Default constructor
	Point(const Point& p);	//Copy constructor
	explicit Point(double val);		//Constructor that takes double as an argument
	Point(double newX, double newY); //New constructor that accepts x and y coordinates of a point
	~Point();	// destructor	

	// Member operator overloading
    Point operator - () const;               // Negate the coordinates. 
	Point operator * (double factor) const;  // Scale the coordinates. 
	Point operator + (const Point& p) const; // Add coordinates. 
	bool operator == (const Point& p) const; // Equally compare operator
	Point& operator = (const Point& source); // Assignment operator. Not const function as changes current object
	Point& operator *= (double factor);      // Scale the coordinates & assign. Not const function as changes current object

	// Accessing functions(selectors)
	double X() const;					// get the x-coordinate using function overloading. Without the const, this will give a compiler error since there is a constant point in the Distancetest file and we getting the x-cord
	double Y() const;					// get the y-coordinate

	//Modifiers
	void X(double newX) {x=newX;};					// set the x coordinate using function overloading and default inline
	void Y(double newY) {y=newY;};					// set the y-coordinate using function overload and default inline

	//Other member functions
	virtual string ToString() const;				// const function as the function does not change point object
	virtual void Draw() const;						// draw function to print out if point has been drawn

	double Distance() const;				// To find distance from origin. change to const function as it does not change point object
	double Distance(const Point& p) const;				// To find distance between two points by call by reference

	friend ostream& operator << (ostream& os, const Point& p); //Send to OS stream
};

inline double Point::X() const { return x; }	//Normal inline function for the getter of x coordinate
inline double Point::Y() const { return y; }	//Normal inline function for the getter of y coordinate

	}
}

#endif