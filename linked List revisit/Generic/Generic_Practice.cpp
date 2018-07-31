#include <iostream>
using namespace std;


// Template Function

template <class T>
T Sum(T a, T b)
{
	return a+b;
}


int main(int argc, char const *argv[])
{
	cout<<"Sum is: "<<Sum(5,7)<<endl;

	return 0;
}