#include <iostream>
using namespace std;

void insertion_sort(int ar[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int hole = ar[i];
		int hole_pos = i;

		for(int j = i-1; j >= 0; ++j)
		{
			if (ar[j] > hole)
			{
				int temp = ar[j];
				ar[j] = hole;
				hole = ar[j];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cout<<"enter the array size"<<endl;
	int n;
	cin>>n;

	int ar[n];

	cout<<"enter the array elements"<<endl;

	for (int i = 0; i < n; ++i)
	{
		cin>>ar[i];
	}


	// insertion sort ascending

	

	return 0;
}