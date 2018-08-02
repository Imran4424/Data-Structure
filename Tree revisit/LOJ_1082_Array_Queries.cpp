#include <iostream>
using namespace std;

const int maxx = 100001;

int ar[maxx] = {0};
int tree[3*maxx] = {0};

void BuidTree(int node, int begin, int end)
{
	if (begin == end)
	{
		tree[node] = ar[begin];

		return;
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (begin+end) / 2;

	BuidTree(left, begin, mid);
	BuidTree(right, mid+1, end);

	tree[node] = min(tree[left],tree[right]);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}