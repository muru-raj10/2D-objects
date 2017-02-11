// circleclass.cpp
//
// Circles in 2D. Defining functions declared in the hpp file.

// Modifications
// 5 July 16, file created

#define _USE_MATH_DEFINES
#include "circleclass.hpp"
#include "Pointclass.hpp"

#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // std::stringstream, std::stringbuffer
using namespace std;

namespace Muru
{
	namespace CAD
	{

Circle::Circle() : Shape(), centrePoint(0.0,0.0), radius(0.0)
{
	//Point centrePoint(0.0,0.0);
	//double radius=0.0;
	cout<<"default circle constructor called"<<endl;
}

Circle::Circle(const Point& p, const double& r) : Shape(), centrePoint(p), radius(r)	//initialise the circle using arguments
{
	//centrePoint=p;
	//radius=r;
	cout<<"point and radius circle constructor called"<<endl;
}

Circle::Circle(const Circle& c) : Shape(c), centrePoint(c.centrePoint) , radius(c.radius) //copy constructor
{
	//centrePoint=c.centrePoint;
	//radius=c.radius;
	cout<<"copy circle constructor called"<<endl;
}

Circle::~Circle() //destructor
{
	cout << "Circle destroyed!\n" <<endl;
}

// Member operator overloading

Circle& Circle::operator = (const Circle& Cir)
{
	if (this != &Cir)
	{
		Shape::operator=(Cir);
		centrePoint=Cir.centrePoint;
		radius=Cir.radius;
	}
	cout<<"circle assigned!"<<endl;
	return *this;

}

//implementing functions

Point Circle::Centre() const	//Get the centre point
{
	return centrePoint;
}

double Circle::Radius() const		//get the radius
{
	return radius;
}

void Circle::Centre(const Point& pt) //set pt to be the centre point
{
	centrePoint=pt;
}

void Circle::Radius(const double& rds) //set a constant to be a radius
{
	radius=rds;
}

string Circle::ToString() const			// To string function to describe the circle
{
	string s=Shape::ToString();
	stringstream sm;							//defining a stringstream
	sm << " Circle with centre ("<<centrePoint.ToString()<<") and radius "<<Radius()<<s<<endl;	
	
	return sm.str();
}

double Circle::Diameter() const				//defining the diameter of a circle
{
	return 2.0*(radius);
}

double Circle::Area() const				//defining the area of a circle
{
	return M_PI*radius*radius;
}

double Circle::Circumference() const				//defining the circumference of a circle
{
	return 2.0*M_PI*radius;
}

void Circle::Draw() const						// draw function to print out if circle has been drawn
{
	cout<<"A Circle has been drawn. The details are as following. " <<ToString()<<endl;
}

ostream& operator << (ostream& os, const Circle& C) //Not a scope resolution operator so no "Point::", it is just a normal global function and can be defined anywhere.	
{ //To print the circle

	os << " Circle with centre "<<C.centrePoint<<" and radius "<<C.radius<<endl;
	return os;
}
	}
}