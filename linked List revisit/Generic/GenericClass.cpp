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


int main(int argc, char const *argv[])
{
	GenericClass<int> objInt(50, 50);

	objInt.Sum(7,8);

	objInt.Sum(10,2.5);

	return 0;
}