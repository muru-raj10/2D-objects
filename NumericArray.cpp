//NumericArray.cpp
//Defining functions of NumericArray.hpp
//Derived class of ArrayTemplate

//Modifications
//19 Jul created

#ifndef NumericArray_cpp  //To avoid multiple inclusion
#define NumericArray_cpp

#define _USE_MATH_DEFINES
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "DimensionException.hpp"
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
template<typename T>
NumericArray<T>::NumericArray() : Array()						//Calling Base class Array's constructor
{
	cout<<"Default NumericArray constructor used"<<endl;
}

//constructor with size argument
template<typename T>
NumericArray<T>::NumericArray(const int& newsize)	: Array(newsize)
{
	cout<<"NumericArray Constructor with size argument used"<<endl;
}

//Copy Constructor using colon syntax
template<typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& NumArr) :	Array(NumArr)	
{
	cout<<"NumericArray Copy constructor used"<<endl;
}

template<typename T>
NumericArray<T>::~NumericArray() 					//destructor
{
	//delete[] data;								//Functionality taken from Base class
	cout << "NumericArray destroyed!" <<endl;
}

// Member operator overloading
template<typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)	//Assignment operator
{
	if (this != &source)				//self asignment check
	{
		Array<T>::operator=(source);	//Use base class functionality
	}
	cout<<"NumericArray assigned!"<<endl;
	return *this;
}

//New operators for derived class
template<typename T>
NumericArray<T> NumericArray<T>::operator * (double factor) const					//Scaling factor
{
	for (int i=0;i<(*this).Size();i++)
	{
		(*this).GetElement(i) *=factor;											//Multiplies each element by the factor
	}
	return *this;
}

template<typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& NumArr) const	//Adding function
{
	if ((*this).Size() == NumArr.Size())
	{

	for (int i=0;i<(*this).Size();i++)
	{
		(*this).GetElement(i) +=NumArr[i];											//Adds each ith element by the ith element of the argument
	}
	return *this;
	}

	else 
	{
		throw DimensionException();										//Throw DimensionException object
	}

}

template<typename T>
T NumericArray<T>::Dot(const NumericArray<T>& NumArr) const				//Dot product
{
	if ((*this).Size()==NumArr.Size())
	{
	T d=0.0;
	for (int i=0;i<(*this).Size();i++)
	{
		d += ((*this).GetElement(i) * NumArr[i]);						//Using a for loop, we add a the product of each element one at a time.
	}
	
	return d;
	}

	else 
	{
		throw DimensionException();										//Throw DimensionException object
	}
}



	}
}



#endif