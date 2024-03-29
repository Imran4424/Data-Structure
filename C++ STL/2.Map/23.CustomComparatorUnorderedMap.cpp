#include <iostream>
#include <map>
#include <unordered_map>
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

	// using comparator as member function
	// operator overloading
	bool operator==(const Point &other) const {
		// true for unique
		// this is little confusing
		// I think the question, isInvalid or not
		// and yes this is invalid
		if (this->row == other.row && this->col == other.col) {
			return true;
		}

		return false;
	}
};

struct Compare
{
	size_t operator()(const Point &x) const {
		size_t rowHash = hash<int>()(x.row);
		size_t colHash = hash<int>()(x.col) << 1;

		return rowHash ^ colHash;
	}
};

int main(int argc, char const *argv[])
{
	// now we can use only the hash
	unordered_map<Point, int, Compare> mapGrid;

	mapGrid[Point(4, 8)] = 25;
	mapGrid[Point(2, 7)] = 13;
	mapGrid[Point(2, 7)] = 1;
	mapGrid[Point(1, 2)] = 7;
	mapGrid[Point(2, 5)] = 12;
	mapGrid[Point(4, 5)] = 25;
	mapGrid[Point(3, 2)] = 15;

	for (auto it = mapGrid.begin(); it != mapGrid.end(); it++) {
		cout << "x = " << it->first.row << ", y = " << it->first.col << ". val = " << it->second << endl;
	}
	
	return 0;
}