//PointArray.hpp
//Derived template class of Array<Point>.
// To add points specific functionality to the Array class in this way

#ifndef PointArray_hpp  //To avoid multiple inclusion
#define PointArray_hpp

#include "ArrayTemplate.hpp"
#include "Shape.hpp"
#include "Pointclass.hpp"
#include <iostream>
using namespace std;
using namespace Muru::CAD;

namespace Muru
{
	namespace Containers
	{
									  								
class PointArray : public Array<Point>				//Concrete inheritance
{
private:											//No private data members

public:
	//Constructors
	PointArray();									//Default constructors
	PointArray(const int& newsize);					// Constructor with size argument
	PointArray(const PointArray& PArr);				//Copy constructor
	virtual ~PointArray();							//Destructor

	//Member operator overloading
	PointArray& operator = (const PointArray& source);		//Assignment operator

	//Member functions
	double Length() const;							//Length function

};
	}
}


#endif