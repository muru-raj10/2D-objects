//Visitor class, a derived class of boost::static_visitor<>

#ifndef Visitor_hpp  //To avoid multiple inclusion
#define Visitor_hpp

#include <iostream>
#include <string>
#include <boost/variant/static_visitor.hpp>
#include "Pointclass.hpp"
#include "lineclass.hpp"
#include "circleclass.hpp"
#include "Shape.hpp"
#include "BadChoiceException.hpp"
using namespace std;
using namespace Muru::CAD;

class Visitor: public boost::static_visitor<>  // Class declaration
{
private:
	double dx;
	double dy;

public:
 
// Visitor constructors, destructor and member functions
	Visitor();
	Visitor(double x, double y);
	~Visitor();
 
	void operator () (Point& p) const;
	void operator () (LineSegment& l) const;
	void operator () (Circle& c) const;

};

#endif