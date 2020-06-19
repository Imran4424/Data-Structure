#include <iostream>
using namespace std;

const int maxx = 1000001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void bulidTree(int node, int startIndex, int endIndex)
{
	if (startIndex == endIndex)
	{
		tree[node] = ar[startIndex];

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	bulidTree(left,startIndex,mid);
	bulidTree(right,mid+1,endIndex);

	tree[node] = tree[left] + tree[right];
}

int Query(int node, int startIndex, int endIndex, int start_index, int endIndex_index)
{
	if (startIndex > endIndex_index || endIndex < start_index)
	{
		return 0;
	}

	if (startIndex >= start_index && endIndex <= endIndex_index)
	{
		return tree[node];
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (startIndex+endIndex) / 2;

	int left_sum = Query(left, startIndex, mid, start_index, endIndex_index);
	int right_sum = Query(right, mid+1, endIndex, start_index, endIndex_index);

	return left_sum + right_sum;
}

void Update(int node, int startIndex, int endIndex, int index, int new_value)
{
	if (index > endIndex || index < startIndex)
	{
		return;
	}

	if (startIndex == index && startIndex == endIndex)
	{
		tree[node] = new_value;

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	Update(left, startIndex, mid, index, new_value);
	Update(right, mid+1, endIndex, index, new_value);

	tree[node] = tree[left] + tree[right];
}


int main(int argc, char const *argv[])
{
	cout << "enter the array size" << endIndexl;

	int size;
	cin >> size;

	cout << "enter the array elements" << endIndexl;

	// starting from 1 cause using 1-index tree
	for (int i = 1; i <= size; ++i) {
		cin >> ar[i];
	}

	bulidTree( 1, 1, size);

	return 0;
}