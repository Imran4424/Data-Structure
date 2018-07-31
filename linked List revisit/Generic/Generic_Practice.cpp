#include <iostream>
using namespace std;


// Template Function

template <class T>
T Sum(T a, T b)
{
	return a + b;
}


int main(int argc, char const *argv[])
{
	cout<<"Sum is: "<<Sum(5,7)<<endl;
	cout<<"Sum is: "<<Sum(5.5, 10.45)<<endl;
	cout<<"Sum is: "<<Sum('a', 'c')<<endl;
	cout<<"Sum is: "<<Sum("I am a ","Programmer")<<endl;

	return 0;
}