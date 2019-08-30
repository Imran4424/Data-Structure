#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

typedef pair< int, pair<int, int> > nestedCouple;

int main(int argc, char const *argv[])
{
	priority_queue < nestedCouple > weightedList;

	int test = 5;

	int source, destination, weight;

	cout << "enter the source, destination and weight" << endl;

	while(test--)
	{
		cin >> source >> destination >> weight;

		weightedList.push(make_pair(weight, make_pair(source, destination)));
	}

	cout << "pairs in priority_queue are" << endl;

	while(!weightedList.empty())
	{
		nestedCouple hand = weightedList.top();
		weightedList.pop();

		cout << hand.first << " " << hand.second.first << " " << hand.second.second << endl;
	}


	return 0;
}
