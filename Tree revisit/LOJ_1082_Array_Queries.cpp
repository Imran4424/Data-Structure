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
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}