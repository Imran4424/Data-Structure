#include <iostream>
using namespace std;

const int maxx = 1000001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void bulidTree(int node, int firstIndex, int end)
{
	if (firstIndex == end)
	{
		tree[node] = ar[firstIndex];

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	bulidTree(left,firstIndex,mid);
	bulidTree(right,mid+1,end);

	tree[node] = tree[left] + tree[right];
}

int Query(int node, int firstIndex, int end, int start_index, int end_index)
{
	if (firstIndex > end_index || end < start_index)
	{
		return 0;
	}

	if (firstIndex >= start_index && end <= end_index)
	{
		return tree[node];
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (firstIndex+end) / 2;

	int left_sum = Query(left, firstIndex, mid, start_index, end_index);
	int right_sum = Query(right, mid+1, end, start_index, end_index);

	return left_sum + right_sum;
}

void Update(int node, int firstIndex, int end, int index, int new_value)
{
	if (index > end || index < firstIndex)
	{
		return;
	}

	if (firstIndex == index && firstIndex == end)
	{
		tree[node] = new_value;

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (left+right) / 2;

	Update(left, firstIndex, mid, index, new_value);
	Update(right, mid+1, end, index, new_value);

	tree[node] = tree[left] + tree[right];
}


int main(int argc, char const *argv[])
{
	cout << "enter the array size" << endl;

	int size;
	cin >> size;

	cout << "enter the array elements" << endl;

	// starting from 1 cause using 1-index tree
	for (int i = 1; i <= size; ++i) {
		cin >> ar[i];
	}

	bulidTree( 1, 1, size);

	return 0;
}