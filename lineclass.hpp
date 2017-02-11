// lineclass.hpp
//
// Header file for finite line segments in 2D. Derived class of shape


#ifndef lineclass_hpp  //To avoid multiple inclusion
#define lineclass_hpp

#include "Pointclass.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

namespace Muru
{
	namespace CAD
	{

class LineSegment : public Shape
{
private:		
		Point startPoint;	// e1
		Point endPoint;		// e2

public:

	// Constructors
	LineSegment();									// Line with both end Points at the origin: Default constructor
	LineSegment(const Point& p1, const Point& p2);	// Copy constructor with start and end Points [p1, p2]
	LineSegment(const LineSegment& l); 				// Copy constructor
	virtual ~LineSegment();							// Destructor

	// Member operator overloading
	LineSegment& operator = (const LineSegment& lineSeg);	// Assignment operator.


	// Accesssing functions
	Point start() const;							// Function overloading. Getters for the start point				
	Point end() const;								// Getters for the end point

	// Modifiers
	void start(const Point& pt);					// Function overloading. Setters : Set start Point pt1
	void end(const Point& pt);						// Set end Point pt2

	//Other member functions
	virtual string ToString() const;						// function disabled and replaced with operator << overloading 
	double Length() const;							//length function to find the length
	virtual void Draw() const;								// draw function to print out if line has been drawn

	friend ostream& operator << (ostream& os, const LineSegment& L); //Send to OS stream
};
	}
}



#endif