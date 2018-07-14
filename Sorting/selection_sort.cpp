#include <iostream>
using namespace std;


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


int main(int argc, char const *argv[])
{
	cout<<"enter the size of the array"<<endl;
	int n;
	cin>>n;

	int ar[n];

	cout<<"enter the array elements"<<endl;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&ar[i]);
	}

	int sorted_array[n];

	sorted_array = selection_sort_ascending(ar,n);

	//Display

	for (int i = 0; i < n; ++i)
	{
		cout<<sorted_array[i]<<" ";
	}

	cout<<endl;

	return 0;
}