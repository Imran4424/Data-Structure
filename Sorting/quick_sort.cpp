#include <iostream>
using namespace std;


int partitioning(int ar[], int start, int end)
{

	int pivot = ar[end];

	int pIndex = start;

	for (int i = start; i < end; ++i)
	{
		if (ar[i] <= pivot)
		{
			int temp = ar[i];
			ar[i] = ar[pIndex];
			ar[pIndex] = temp;

			pIndex++;
		}
	}

	int temp = ar[end];
	ar[end] = ar[pIndex];
	ar[pIndex] = temp;


	return pIndex;
}


void quick_sort(int ar[], int start,int end)
{
	if (start < end)
	{
		int pIndex = partitioning(ar,start,end);

		quick_sort(ar,start,pIndex-1);
		quick_sort(ar,pIndex+1,end);
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


	// calling quick sort

	quick_sort(ar,0,n-1);

	// Display

	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" ";
	}

	cout<<endl;

	return 0;
}