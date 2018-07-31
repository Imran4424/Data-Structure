#include <iostream>
#include <string>
using namespace std;


// Template Function

template <class T>
T Sum(T a, T b)
{
	return a + b;
}


int main(int argc, char const *argv[])
{
	string first = "I am a ";
	string second = "Programmer";

	cout<<"Sum is: "<<Sum(5,7)<<endl;
	cout<<"Sum is: "<<Sum(5.5, 10.45)<<endl;
	cout<<"Sum is: "<<Sum('a', '5')<<endl;
	cout<<"Sum is: "<<Sum(first, second)<<endl;

	return 0;
}