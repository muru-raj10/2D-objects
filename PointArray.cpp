//NumericArray.cpp
//Defining functions of NumericArray.hpp
//Derived class of Array<Point> 

//Modifications
//20 Jul created

#ifndef PointArray_cpp  //To avoid multiple inclusion
#define PointArray_cpp

#define _USE_MATH_DEFINES
#include "PointArray.hpp"
#include "ArrayException.hpp"
#include "DimensionInappropriate.hpp"
//#include "Pointclass.hpp"
//#include "Shape.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // std::stringstream, std::stringbuffer
using namespace std;

namespace Muru
{
	namespace Containers
	{

//Default constructor using colon syntax
	
PointArray::PointArray() : Array()						//Calling Base class Array's constructor which creates points as elements
{
	cout<<"Default PointArray constructor used"<<endl;
}

//constructor with size argument

PointArray::PointArray(const int& newsize)	: Array(newsize)
{
	cout<<"PointArray Constructor with size argument used"<<endl;
}

//Copy Constructor using colon syntax

PointArray::PointArray(const PointArray& PArr) :	Array(PArr)	
{
	cout<<"PointArray Copy constructor used"<<endl;
}


PointArray::~PointArray() 					//destructor
{
	//delete[] data;								//Functionality taken from Base class
	cout << "PointArray destroyed!" <<endl;
}

// Member operator overloading

PointArray& PointArray::operator = (const PointArray& source)	//Assignment operator
{
	Array<Point>::operator=(source);	//Use base class functionality
	
	cout<<"PointArray assigned!"<<endl;
	return *this;
}


double PointArray::Length() const									//Length function
{
	if ((*this).Size()>1)
	{
		double length=0.0;

		for (int i=0;i<(*this).Size()-1;i++)
		{
			length += ((*this)[i]).Distance((*this)[i+1]);						//Using a for loop, we add a the product of each element one at a time.
		//We may want also use	length += ((*this).GetElement(i)).Distance((*this).GetElement(i+1));
		} 
	
		return length;
	}

	else 
	{
		throw DimensionInappropriate();										//Throw DimensionException object
	}
}



	}
}



#endif