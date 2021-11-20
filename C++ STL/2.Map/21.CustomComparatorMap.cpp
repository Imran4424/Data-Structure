#include <iostream>
#include <map>
using namespace std;

struct Point
{
	int row;
	int col;

	Point() {
		row = 0;
		col = 0;
	}

	Point(int row, int col) {
		this->row = row;
		this->col = col;
	}
};

// custom comparator for sorting the map by row
// if row equals then by column
// parameter is value type so no need of const
// older compiler may will give your error this
// this will not run in visual studio
struct Compare
{
	bool operator()(Point x, Point y) {
		if (x.row == x.col) {
			return x.col < y.col;
		}

		// lesser than for ascending sorting
		return x.row < y.row;
	}
};


// parameter is reference type
// so we must use const before all paramter
// older compiler may will give your error this
// this will not run in visual studio
struct CompareConst
{
	bool operator()(const Point &x, const Point &y) {
		if (x.row == x.col) {
			return x.col < y.col;
		}

		// lesser than for ascending sorting
		return x.row < y.row;
	}
};


// parameter is reference type
// so we must use const before all paramter
// also put const afer method declaration
// this will satisfy all compiler
// safest declaration
struct CompareConstAll
{
	bool operator()(const Point &x, const Point &y) const {
		if (x.row == x.col) {
			return x.col < y.col;
		}

		// lesser than for ascending sorting
		return x.row < y.row;
	}
};


int main(int argc, char const *argv[])
{
	map<Point, int, Compare> mapGrid;

	mapGrid[Point(4, 8)] = 25;
	mapGrid[Point(2, 7)] = 13;
	mapGrid[Point(1, 2)] = 7;
	mapGrid[Point(2, 5)] = 12;
	mapGrid[Point(4, 5)] = 25;
	mapGrid[Point(3, 2)] = 15;

	for (auto it = mapGrid.begin(); it != mapGrid.end(); it++) {
		cout << "x = " << it->first.row << ", y = " << it->first.col << ". val = " << it->second << endl;
	}
	
	return 0;
}

/*
	Custom comparator map

	https://stackoverflow.com/questions/5733254/how-can-i-create-my-own-comparator-for-a-map
*/