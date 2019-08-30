#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair <int, int> couple;

struct compare
{
	bool operator()(couple& a, couple& b)
	{
		return a.second < b.second;
	}
};

int main(int argc, char const *argv[])
{
	priority_queue < couple, vector<couple>,  compare > priceList;

	int id, price, test;

	test = 5;

	while(test --)
	{
		cin >> id >> price;

		priceList.push(make_pair(id, price));
	}

	while(!priceList.empty())
	{
		couple hand = priceList.top();
		priceList.pop();

		cout << hand.first << " " << hand.second << endl;
	}

	return 0;
}