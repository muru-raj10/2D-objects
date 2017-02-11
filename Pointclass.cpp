// Pointclass.cpp
//
// Points in two dimensions and their functions. Defining functions declared in the hpp file.

// Modifications
// 3 July 16, file created
// 9 July 16, file updated with operator overloading
//14 July 16, updated with colon syntax and as derived class of shape

#include "Pointclass.hpp"
#include <cmath>
#include <sstream> // std::stringstream, std::stringbuffer
using namespace std;

namespace Muru
{
	namespace CAD
	{

Point::Point() : Shape(), x(0.0),y(0.0)		//colon syntax
{//Default constructor
	//x = y =0.0;
	cout<< "Default point constructor called!"<<endl;
}

Point::Point(const Point& p)  : Shape(p) ,x(p.x),y(p.y)      //copy constructor
{
    //x = p.x;
    //y = p.y;
	cout << "copy point constructor used!"<<endl;
}

Point::Point(double val) : Shape(),x(val),y(val)			//initialize to a point on the line y=x.
{
	//x=val;
	//y=val;
}

Point::Point(double newX, double newY) : Shape(),x(newX), y(newY) //initialize new coordinates x and y of a point
{
	//x = newX;
    //y = newY;
	cout<<"coordinates Point constructor used"<<endl;
}

Point::~Point() 
{// Destructor
	cout<<"Point destroyed!"<<endl;
}

// Member operator overloading

Point Point::operator - () const // The additive inverse of the current point
{ 
	return Point(- x, - y);
}

Point Point::operator * (double factor) const //Scaling the current point by a factor.
{
	return Point(factor*x, factor*y);
}

Point Point::operator + (const Point& p) const //Adding the x and y coordinates of 2 points. Vector addition
{
	return Point(x+p.x,y+p.y);
}

bool Point::operator == (const Point& p) const // To compare two points, return true if they are the same.
{
	return (x == p.x && y == p.y);
}

Point& Point::operator = (const Point& source) // Assignment operator.
{
	if(this != &source)
	{
		Shape::operator=(source);
		x=source.x;
		y=source.y;
	}
	cout<<"Point assigned!"<<endl;
	return *this;	//current object returned. No copy made.
}

Point& Point::operator *= (double factor)      // Scale the coordinates & assign.
{
	x=factor*x;
	y=factor*y;
	return *this;
}

//implementing the functions
// Getter and setter functions are normal and default inline functions respectively defined in the hpp file

//double Point::X() const  
//{
//	return x; //return a copy of x
//}

//double Point::Y() const
//{
//	return y; //return a copy of y
//}

//void Point::X(double newX) 
//{
//	x=newX; //changing the x coordinate to the new x coordinate
//}

//void Point::Y(double newY) 
//{
//	y=newY; //changing the y coordinate to the new y coordinate
//}

string Point::ToString() const
{
	string s=Shape::ToString();
	stringstream ss;							//defining a stringstream
	ss << "Point ("<<X()<<","<<Y()<<")"<<s;	
	
	return ss.str();							
}

void Point::Draw() const						// draw function to print out if point has been drawn
{
	cout<<"A point has been drawn. The details are as following. " <<ToString()<<endl;
}

double Point::Distance() const
{
	return sqrt(x*x+y*y);						//defining the distance of a point from origin
}

double Point::Distance(const Point& p) const//defining by reference
{
	return sqrt(pow((x-p.x),2)+pow((y-p.y),2));	//defining using pow from cmath of a point from a point p
	
}

ostream& operator << (ostream& os, const Point& p) //Not a scope resolution operator so no "Point::", it is just a normal global function and can be defined anywhere.	
{ //To print the point

	os << "Point(" <<p.x<<","<<p.y<<")"<<endl;
	return os;
}

}
}