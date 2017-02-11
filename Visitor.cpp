//Define functions from Visitor.hpp

#include <iostream>
#include <string>
#include <boost/variant/static_visitor.hpp>
#include "Pointclass.hpp"
#include "lineclass.hpp"
#include "circleclass.hpp"
#include "Shape.hpp"
#include "BadChoiceException.hpp"
#include "Visitor.hpp"
using namespace std;
using namespace Muru::CAD;

Visitor::Visitor() : dx(0) ,dy(0)
{//default constructor
}

Visitor::Visitor(double x, double y) : dx(x) ,dy(y)
{//Constructor with 2 elements
}

Visitor::~Visitor() 
{// Destructor
	cout<<"Visitor destroyed!"<<endl;
}

void Visitor::operator () (Point& p) const
{
	p.X(p.X()+dx);   
	p.Y(p.Y()+dy);
}

void Visitor::operator () (LineSegment& l) const
{
	l.start( Point (l.start().X()+dx, l.start().Y()+dy) );
	l.end( Point (l.end().X()+dx, l.end().Y()+dy) );
}

void Visitor::operator () (Circle& c) const
{
	c.Centre( Point (c.Centre().X()+dx, c.Centre().Y()+dy) );
}