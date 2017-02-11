// ArrayTemplate.cpp
//
// arrays. Defining functions declared in the hpp file. 

// Modifications
// 10 July 16, file created
//15 July 16, exception handling entered
//19 July 16. Arrayclass is changed to template Array<T>. Add in static variable for default size


#ifndef ArrayTemplate_cpp  //To avoid multiple inclusion
#define ArrayTemplate_cpp

#define _USE_MATH_DEFINES
#include "ArrayTemplate.hpp"
//#include "Shape.hpp"
//#include "Pointclass.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // std::stringstream, std::stringbuffer
using namespace std;

namespace Muru
{
	namespace Containers
	{

template<typename T>
int Array<T>::default_size=10;

template<typename T>
Array<T>::Array() : size(default_size) , data(new T[default_size])						//Default constructor
{
	//size=default_size;							//using static default size variable
	//data=new T[size];
	cout<<"Default constructor used"<<endl;
}

template<typename T>
Array<T>::Array(const int& newsize)	: size(newsize) , data(new T[newsize])		//constructor with size argument
{
	//size = newsize;
	//data=new T[newsize];
	cout<<"Constructor with size argument used"<<endl;
}

template<typename T>
Array<T>::Array(const Array<T>& A)	: size(A.size) , data(new T[A.size])	//copy constructor 
{
	//size=A.size;
	//data=new T[size];
	
	for (int i=0;i<size;i++)			//copies each element
	{
		data[i]=A.data[i];
	}
	cout<<"Copy constructor used"<<endl;
}

template<typename T>
Array<T>::~Array()						//destructor
{
	delete[] data;					//deallocate the array
	cout << "Array destroyed!" <<endl;
}

// Member operator overloading
template<typename T>
Array<T>& Array<T>::operator = (const Array<T>& Arr)			// Assignment operator reference from http://www.geeksforgeeks.org/g-fact-38/
{
	if (this != &Arr)				//self asignment check
	{
		delete[] data;				//deallocate old memory

		data=new T[Arr.size];	//allocate new memory
		size=Arr.size;				//copy size and elements
		
		for (int i=0;i<size;i++)
		{
			data[i]=Arr.data[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::GetElement(int position) const						// Getter for the array elements. return by reference
{
	if (0<=position && position<size)							//if position is within limits, return the element
	{
		return data[position];
	}

	else
	{
		throw OutOfBoundsException(position);						//Throw OOBE object with erroneous position for out of bounds
		//cout<<"Out of bounds"<<endl;
		//return data[0];											//else return the first element
	}															
}

template<typename T>
void Array<T>::SetElement(int position, const T& pt)				//  Setter for the array element
{
	if (0<=position && position<size)
	{
		data[position]=pt;
	}

	else
	{
		throw OutOfBoundsException(position);						//Throw OOBE object with erroneous position for out of bounds
		//cout<<"Out of bounds"<<endl;
	}																//ignore command and do nothing
}

template<typename T>
int Array<T>::Size() const											//Size function
{
	return size;
}

template<typename T>
int Array<T>::DefaultSize()											//function to get default Size 
{
	return default_size;
}

template<typename T>
int Array<T>::DefaultSize(int newdefaultsize) 						//function to set default Size 
{
	default_size=newdefaultsize;
	return default_size;
}

template<typename T>
T& Array<T>:: operator [] (int position)							//square bracket operator
{
	if (0<=position && position<size)							//if position is within limits, return the element
	{
		return data[position];
	}

	else
	{
		throw OutOfBoundsException(position);						//Throw OOBE object with erroneous position for out of bounds
		
		//cout<<"Out of bounds"<<endl;
		//return data[0];											//else return the first element
	}
}

template<typename T>
const T& Array<T>:: operator [] (int position) const				//square bracket operator
{
	if (0<=position && position<size)							//if position is within limits, return the element
	{
		return data[position];
	}

	else
	{
		throw OutOfBoundsException(position);						//Throw OOBE object with erroneous position for out of bounds
		//cout<<"Out of bounds"<<endl;
		//return data[0];											//else return the first element
	}
}
	}
}
#endif
	