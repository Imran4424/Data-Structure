#include <iostream>
using namespace std;

template <class T>
class GenericClass
{
	private: T first,second;
	
	public: GenericClass(T a, T b)
	{
		first = a;
		second = b;
	}

	public: T Sum(T x, T y)
	{
		return x+y;
	}
	
};