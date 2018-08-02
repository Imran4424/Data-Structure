#include <iostream>
using namespace std;

const int maxx = 1000001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void BuildTree(int node, int begin, int end)
{
	if (begin == end)
	{
		tree[node] = ar[begin];

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	BuildTree(left,begin,mid);
	BuildTree(right,mid+1,end);

	tree[node] = tree[left] + tree[right];
}

int Query(int node, int begin, int end, int start_index, int end_index)
{
	if (begin > end_index || end < start_index)
	{
		return 0;
	}

	if (begin >= start_index && end <= end_index)
	{
		return tree[node];
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (begin+end) / 2;

	int left_sum = Query(left, begin, mid, start_index, end_index);
	int right_sum = Query(right, mid+1, end, start_index, end_index);

	return left_sum + right_sum;
}

void Update(int node, int begin, int end, int index, int new_value)
{
	if (index > end || index < begin)
	{
		return;
	}

	if (begin == index && begin == end)
	{
		tree[node] = new_value;

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	Update(left, begin, mid, index, new_value);
	Update(right, mid+1, end, index, new_value);

	tree[node] = tree[left] + tree[right];
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

	Query


	return 0;
}