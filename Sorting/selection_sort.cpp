#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	cout<<"enter the size of the array"<<end;
	int n;
	cin>>n;

	int ar[n];

	cout<<"enter the array elements"<<endl;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&ar[i]);
	}

	


	return 0;
}