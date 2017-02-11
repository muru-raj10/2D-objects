// lineclass.cpp
//
// Linesegments in 2D. Defining functions declared in the hpp file.

// Modifications
// 4 July 16, file created
// 14 July 16, colon syntax and as a derived class of shape
#ifndef lineclass_cpp  //To avoid multiple inclusion
#define lineclass_cpp

#include "lineclass.hpp"
#include "Pointclass.hpp"
#include <cmath>
#include <string>
#include <sstream> // std::stringstream, std::stringbuffer
using namespace std;

namespace Muru
{
	namespace CAD
	{

LineSegment::LineSegment() : Shape(), startPoint(0.0,0.0),endPoint(0.0,0.0) //colon syntax
{
	//Point startPoint(0.0,0.0);
	//Point endPoint(0.0,0.0);

	cout << "Default line segment constructor used!\n" <<endl;
}

LineSegment::LineSegment(const Point& p1, const Point& p2) : Shape(), startPoint(p1), endPoint(p2)
{
	//startPoint=p1;
	//endPoint=p2;

	cout << "Line segment constructor used to define 2 points!\n" <<endl;
}

LineSegment::LineSegment(const LineSegment& l) : Shape(l), startPoint(l.startPoint), endPoint(l.endPoint)//copy constructor
{
	//startPoint=l.startPoint;
	//endPoint=l.endPoint;

	cout << "Copy line segment constructor used!\n" <<endl;
}

LineSegment::~LineSegment() //destructor
{
	cout << "Line segment destroyed!\n" <<endl;
}

// Member operator overloading

LineSegment& LineSegment::operator = (const LineSegment& LineSeg)
{
	if (this != &LineSeg)
	{
		Shape::operator=(LineSeg);
		startPoint=LineSeg.startPoint;
		endPoint=LineSeg.endPoint;
	}
	cout<<"Line assigned!"<<endl;		//To put before return *this
	return *this;
}

//implementing functions

Point LineSegment::start() const	//Get the start point
{
	return startPoint;
}

Point LineSegment::end() const		//get the end point
{
	return endPoint;
}

void LineSegment::start(const Point& pt) //set pt to be the start point
{
	startPoint=pt;
}

void LineSegment::end(const Point& pt) //set pt to be the end point
{
	endPoint=pt;
}

string LineSegment::ToString() const
{
	string s=Shape::ToString();
	stringstream st;							//defining a stringstream
	st << "Line from the "<<startPoint.ToString()<<" to the "<<endPoint.ToString()<<s<<endl;	
	
	return st.str();
}

double LineSegment::Length() const				//using Distance function defined in Pointclass
{
	return startPoint.Distance(endPoint);
}

void LineSegment::Draw() const						// draw function to print out if line has been drawn
{
	cout<<"A line has been drawn. The details are as following. " <<ToString()<<endl;
}

ostream& operator << (ostream& os, const LineSegment& L) //Not a scope resolution operator so no "Point::", it is just a normal global function and can be defined anywhere.	
{ //To print the line

	os << "Line from the "<<L.startPoint<<" to the "<<L.endPoint<<endl;
	return os;
}
	}
}
#endif