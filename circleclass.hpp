// circleclass.hpp
//
// Header file for circles in 2D. Derived class of Shape


#ifndef circleclass_hpp  //To avoid multiple inclusion
#define circleclass_hpp

#include "Pointclass.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

namespace Muru
{
	namespace CAD
	{

class Circle : public Shape
{
private:		
		Point centrePoint;	
		double radius;

public:

	// Constructors
	Circle();										// Circle with centre and radius: Default constructor
	Circle(const Point& p, const double& r);		// Copy constructor with centre and radius
	Circle(const Circle& c); 						// Copy constructor
	virtual ~Circle();								// Destructor

	// Member operator overloading
	Circle& operator = (const Circle& Cir);			// Assignment operator.

	// Accesssing functions
	Point Centre() const;							// Getters for the centre point				
	double Radius() const;							// Getters for the radius

	// Modifiers
	void Centre(const Point& pt);					// Function overloading. Setters : Set the centre point
	void Radius(const double& rds);					// Set the radius

	//Other member functions
	virtual string ToString() const;						// function disabled and replaced with operator << overloading 
	virtual double Diameter() const;						// Diameter function to find the diameter

	double Area() const;							// Area function to find the area 

	double Circumference() const;					// to find the circumference

	void Draw() const;								// draw function to print out if circle has been drawn


	friend ostream& operator << (ostream& os, const Circle& C); //Send to OS stream
};

	}
}
#endif