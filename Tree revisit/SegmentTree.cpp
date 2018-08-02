#include <iostream>
using namespace std;

const int maxx = 1000001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void BuildTree(int node, int begin, int end)
{
	if (begin == end)
	{
		tree[begin] = ar[begin];

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	BuildTree(left,begin,mid);
	BuildTree(right,mid+1,end);

	tree[node] = tree[left] + tree[right];
}

int Query(int node,int begin,int end, int start_index, int end_index)
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

	BuildTree(1,1,size);

	return 0;
}