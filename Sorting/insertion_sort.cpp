#include <iostream>
using namespace std;


/*
	insertion sort ascending

	but 

	also can be used it for insertion sort but print the array in reverse order
*/

void insertion_sort(int ar[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int hole_pos = i;
		

		for(int j = i-1; j >= 0; --j)
		{
			if (ar[j] > ar[hole_pos])
			{
				int temp = ar[j];
				ar[j] = ar[hole_pos];
				ar[hole_pos] = temp;

				hole_pos = j;
			}
		}
	}
}

void insertion_sort_decending(int ar[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int hole_pos = i;
		

		for(int j = i-1; j >= 0; --j)
		{
			if (ar[j] < ar[hole_pos])
			{
				int temp = ar[j];
				ar[j] = ar[hole_pos];
				ar[hole_pos] = temp;

				hole_pos = j;
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

	insertion_sort(ar,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" ";
	}

	cout<<endl;

	// insertion sort ascending

	insertion_sort_decending(ar,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" ";
	}

	cout<<endl;

	return 0;
}