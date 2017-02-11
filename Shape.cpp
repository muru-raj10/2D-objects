// Shape.cpp
//
// Defining functions for shape
// Modifications
// 14 July 16, file created

#ifndef Shape_cpp  //To avoid multiple inclusion
#define Shape_cpp

#include "Shape.hpp"
#include <cmath>
#include <sstream> // std::stringstream, std::stringbuffer
#include "stdlib.h";
using namespace std;

Shape::Shape() : id(rand())
{//default constructor
	cout<<"Default shape constructor used"<<endl;
}

Shape::Shape(const Shape& sh) : id(sh.id)
{//copy constructor
	cout<<"Copy shape constructor used!"<<endl;
}

Shape::~Shape()
{//destructor
	cout<<"Shape destructor used!"<<endl;
}

// Member operator overloading
Shape& Shape::operator = (const Shape& source) // Assignment operator.
{
	if(this != &source)
	{
	id=source.id;
	}
	
	return *this;	//current object returned. No copy made.
}

//Retrive the id
int Shape::ID() const
{
	return id;
}

string Shape::ToString() const
{
	stringstream ss;							//defining a stringstream
	ss << " ID: "<<ID()<<endl;	
	
	return ss.str();							
}

/*void Shape::Draw() const
{//empty implementation as you cannot draw a shape.
							
}*/

void Shape::Print() const
{
	cout<<ToString()<<endl;			//Call print function as a function of the polymorphic function ToString(). ToString() is overridden in the derived classes. 
}
#endif