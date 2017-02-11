//Stackclass.cpp
//To define the functions declared in Stackclass.hpp
//Layering Exceptions. Translate array exceptions to stack exceptions.
//To use an int value as a template variable

#ifndef Stackclass_cpp  //To avoid multiple inclusion
#define Stackclass_cpp

#include"ArrayTemplate.hpp"
#include "Stackclass.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
#include <iostream>
using namespace std;		
using namespace Muru::Containers;



template<typename T,int size>
Stack<T,size>::Stack() : A(size) , current(0)			//Default constructor. We call on the size constructor in Array. creates an array and current pointing to top of the stack
{
	cout<<"Default Stack constructor called"<<endl;
}
/*
template<typename T>
Stack<T>::Stack(const int& newsize) : A(newsize) , current(0)			//Constructor with new size
{
	cout<<"Size Stack constructor called"<<endl;
}*/

template<typename T,int size>
Stack<T,size>::Stack(const Stack<T,size>& S) : A(S.A) , current(S.current)					//copy constructor
{
	cout<<"Stack copy constructor called"<<endl;
}

template<typename T,int size>
Stack<T,size>::~Stack() 												//Destructor
{
	cout<<"Stack destroyed"<<endl;
}

// Member operator overloading
template<typename T,int size>
Stack<T,size>& Stack<T,size>::operator = (const Stack<T,size>& Arr)			// Assignment operator reference from http://www.geeksforgeeks.org/g-fact-38/
{
	A=Arr.A;								//Use Array class functionality
	current=Arr.current;

	cout<<"Stack assigned!"<<endl;
	return *this;
}

//Other member functions
template<typename T,int size>
void Stack<T,size>::Push(const T& p)			//push function
{
	try
	{
	A[current]=p;								//stores element at the current position. When current is at max size of stack, Out of bounds error is triggered and the subsequent line current is not incremented
	current++;									//current position incremented
	cout<< p << " pushed onto Stack and the current size is "<<current<< endl;
	}

	catch(ArrayException& err)					//Catch block to catch the object thrown by array class
	{
	current =size;								//No longer using Size() function but the template variable//resets current to the size of the array
	throw StackFullException(current);			//Throws a stack exception which is an abstract base class object.
	}
}

/*template<typename T>
T Stack<T>::Pop()
{	
	int temp= current;
	temp--;
	cout<< A[temp] << " popped off the Stack and the current index is "<<temp<< endl;
	current--;
	return A[temp];
	
	
}*/

template<typename T,int size>
T Stack<T,size>::Pop()					//Pop function
{	
	try
	{
	A[current-1];						//When current is at 0 and there isn't any element left, out of bounds error is triggered and current is not decremented any further.
	cout<< A[current-1] << " popped off the Stack and the current size is "<<current-1<< endl;
	return A[--current];				//function returns the element popped.
	}

	catch(ArrayException& err)			//Catch block to catch the object thrown by array class
	{
	current =0;							//resets current to the 0 since empty
	throw StackEmptyException();		//Throws a stack exception which is an abstract base class object.
	}
}


#endif
