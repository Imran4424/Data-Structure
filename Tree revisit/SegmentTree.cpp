#include <iostream>
using namespace std;

const int maxx = 1000001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void BuildTree(int node, int begin, int end)
{

}


int main(int argc, char const *argv[])
{
	cout<<"enter the array size"<<endl;

	int size;
	cin>>size;

	cout<<"enter the array elements"<<endl;

	for (int i = 1; i <= size; ++i)
	{
		cin>>ar[i];
	}

	return 0;
}