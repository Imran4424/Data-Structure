#include <iostream>
using namespace std;


int partitioning(int ar, int start, int end)
{

	int pivot = ar[end];

	int pIndex = start;

	for (int i = start; i < end; ++i)
	{
		if (ar[i] <= pivot)
		{
			int temp = ar[start];
			ar[start] = ar[pIndex];
			ar[pIndex] = temp;

			pIndex++;
		}
	}

	int temp = ar[end];
	ar[end] = ar[pIndex];
	ar[pIndex] = temp;


	return pIndex;
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