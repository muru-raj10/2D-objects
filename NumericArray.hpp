//NumericArray.hpp
//Derived template class of ArrayTemplate.
//adding numeric functionality to the Array class like calculating the sum, that would limit the types possible as the template argument to types that support numeric operations. 

#ifndef NumericArray_hpp  //To avoid multiple inclusion
#define NumericArray_hpp

#include "ArrayTemplate.hpp"
#include <iostream>
using namespace std;		

namespace Muru
{
	namespace Containers
	{
													//We assume that the type T is a double or an int when we define our functions in the cpp file to attain the required functionality. However, T is still generic
template <typename T>								//If we define template <typename T=double>, then we cannot create Numeric arrays with points. Here we still can but it will fail when a numeric functionality function is called that is not defined for points.
class NumericArray : public Array<T>				//generic inheritance
{
private:											//No private data members

public:
	//Constructors
	NumericArray();									//Default constructors
	NumericArray(const int& newsize);				// Constructor with size argument
	NumericArray(const NumericArray<T>& NumArr);	//Copy constructor
	virtual ~NumericArray();						//Destructor

	//Member operator overloading
	NumericArray<T>& operator = (const NumericArray<T>& source);		//Assignment operator

	//New operators for derived class
	NumericArray<T> operator * (double factor) const;					//Scaling factor
	NumericArray<T> operator + (const NumericArray<T>& NumArr) const;	//Adding two Numeric array elements of equal size

	//Member functions
	T Dot(const NumericArray<T>& NumArr) const;			//Dot product 

};
	}
}

#ifndef NumericArray_cpp					//To include cpp file
#include "NumericArray.cpp"
#endif

#endif