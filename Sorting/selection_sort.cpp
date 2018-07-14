#include <iostream>
using namespace std;


// returning a whole array

int* selection_sort_ascending(int ar[], int s)
{

	for(int i = 0;i < s; i++)
	{
		int min = 999999999,pos = 0;

		for(int j = i;j < s; j++)
		{
			if (ar[j] < min)
			{
				min = ar[j];
				pos = j;
			}
		}

		int temp = ar[pos];
		ar[pos] = ar[i];
		ar[i] = temp;

	}

	return ar;
}

int* selection_sort_decending(int ar[], int s)
{

	for(int i = 0;i < s; i++)
	{
		int max = -999999,pos = 0;

		for(int j = i;j < s; j++)
		{
			if (ar[j] > max)
			{
				max = ar[j];
				pos = j;
			}
		}

		int temp = ar[pos];
		ar[pos] = ar[i];
		ar[i] = temp;

	}

	return ar;
}


int main(int argc, char const *argv[])
{
	cout<<"enter the size of the array"<<endl;
	int n;
	cin>>n;

	int ar[n];

	cout<<"enter the array elements"<<endl;

	for (int i = 0; i < n; ++i)
	{
		cin>>ar[i];
	}

	//catching a whole array

	int *sorted_array = selection_sort_ascending(ar,n);

	//Display

	for (int i = 0; i < n; ++i)
	{
		cout<<sorted_array[i]<<" ";
	}

	cout<<endl;

	int *sorted_array_decending = selection_sort_decending(ar,n);

	return 0;
}