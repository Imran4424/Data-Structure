#include <iostream>
using namespace std;

int* bubble_sort(int ar[],int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		for(int j = 0; j < size-1-j; ++j)
		{
			if (ar[j] > ar[j+1])
			{
				/* code */
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int ar[n];

	cout<<"enter the array elements"<<endl;

	for (int i = 0; i < n; ++i)
	{
		cin>>ar[i];
	}


	return 0;
}