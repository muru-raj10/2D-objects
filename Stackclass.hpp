//Stackclass.hpp
//A template class for stack using composition in which the data member is from Array<T>. We can use Array<T> for data storage without inheriting operations that Stack does not require.
//In this case the Stack class uses internally an Array class. Forwarding functionality to another class is called delegation. Here the Stack class delegates the storage of elements to the Array class. 
//Header file for Stack class

#ifndef Stackclass_hpp  //To avoid multiple inclusion
#define Stackclass_hpp

#include"ArrayTemplate.hpp"
#include <iostream>
using namespace std;		
using namespace Muru::Containers;

template<typename T, int size>
class Stack
{
private:
					//Data members
	Array<T> A;
	int current;

public:
	//Constructors
	Stack();						//Default Constructor
	Stack(const Stack<T,size>& S);		//Copy constructor
	~Stack();						//Destructor

	// Member operator overloading
	Stack<T,size>& operator = (const Stack<T,size>& Arr);			// Assignment operator	

	//Other member functions

	void Push(const T& Arr);					//Push function
	T Pop();									//Pop function

};

#ifndef Stackclass_cpp		
#include "Stackclass.cpp"	
#endif

#endif