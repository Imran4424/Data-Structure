#include <iostream>
using namespace std;

void merge(int left[],int size_left,int right[], int size_right, int ar[])
{
	int i = 0, j = 0, k = 0;

	while(i < size_left && j < size_right)
	{
		
	}
}


void merge_sort(int ar, int size)
{
	if (size < 2)
	{
		return;
	}

	int mid = size/2;

	int left[mid],right[size-mid];

	for (int i = 0; i < mid; ++i)
	{
		left[i] = a[i];
	}

	for (int i = mid; i < size; ++i)
	{
		right[i-mid] = ar[i];
	}

	merge_sort(left,mid);
	merge_sort(right,size-mid);
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

	return 0;
}