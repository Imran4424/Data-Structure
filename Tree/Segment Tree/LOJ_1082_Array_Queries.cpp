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

int Query(int node, int begin, int end, int start_index, int end_index)
{
	if (start_index > end || end_index < begin)
	{
		return 9999999;
	}

	if (begin >= start_index && end <= end_index)
	{
		return tree[node];
	}

	int left = node*2;
	int right = node*2 + 1;

	int mid = (begin+end) / 2;

	int left_value = Query(left, begin, mid, start_index, end_index);
	int right_value = Query(right, mid+1, end, start_index, end_index);

	return min(left_value, right_value);
}

int main(int argc, char const *argv[])
{
	int test;
	cin>>test;

	for (int t = 1; t <= test; ++t)
	{
		int array_size, num_queries;
		cin>>array_size>>num_queries;


		for (int i = 1; i <= array_size; ++i)
		{
			cin>>ar[i];
		}

		BuidTree(1,1,array_size);

		cout<<"Case 1:"<<endl;

		for (int i = 0; i < num_queries; ++i)
		{
			int x,y;
			cin>>x>>y;

			int min_value = Query(1,1,array_size,x,y);

			cout<<min_value<<endl;
		}
	}

	return 0;
}