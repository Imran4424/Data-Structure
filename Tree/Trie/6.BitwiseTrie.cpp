#include <iostream>
#include <string>
using namespace std;

struct Node
{
	bool endMark;
	Node* left; // 0
	Node* right; // 1

	Node() {
		endMark = false;
		left = right = NULL;
	}
};

class Trie
{
	Node *root;

	void eraseAll(Node *travel) {
		if (travel->left) {
			eraseAll(travel->left);
		}

		if (travel->right) {
			eraseAll(travel->right);
		}

		delete travel;
	}


	int maxVal(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	Trie() {
		root = new Node();
	}

	void reset() {
		root = new Node();
	}

	void insertString(string number) {
		Node* travel = root;

		for (int i = 0; number[i]; i++) {
			if ('0' == number[i]) {
				if (NULL == travel->left) {
					travel->left = new Node();
				}

				travel = travel->left;
			} else {
				if (NULL == travel->right) {
					travel->right = new Node();
				}

				travel = travel->right;
			}
		}

		travel->endMark = true;
	}

	void insertInt(int number) {
		Node *travel = root;

		// bits from that number in the trie
		// from most significant bit to least significant bit
		// this is a 32 bit binary conversion of int number
		// all number need to fixed bit for XOR operation
		for (int i = 31; i >= 0; i--) {
			int bit = (number >> 1) & 1;
			if (0 == bit) {
				if (NULL == travel->left) {
					travel->left = new Node();
				}

				travel = travel->left;
			} else {
				if (NULL == travel->right) {
					travel->right = new Node();
				}

				travel = travel->right;
			}
		}

		travel->endMark = true;
	}

	// this method will as complement operation
	int maxXORHelper(int number) {
		int currentAns = 0;
		Node* travel = root;

		// bits from that number in the trie
		// from most significant bit to least significant bit
		// this is a 32 bit binary conversion of int number
		// all number need to fixed bit for XOR operation
		for (int i = 31; i >= 0; i--) {
			int bit = (number >> i) & 1;

			if (0 == bit) {
				// find the opposite value
				if (travel->right) {
					travel = travel->right;
					currentAns += (1 << i);
				} else {
					travel = travel->left;
				}
			} else {
				// fin the opposite value
				if (travel->left) {
					travel = travel->left;
					currentAns += (1 << i);
				} else {
					travel = travel->right;
				}
			}
		}

		return currentAns;
	}

	int maxXOR(int input[], int nSize) {
		int mXOR = 0;

		for (int i = 0; i < nSize; i++) {
			insertInt(input[i]);
			int currentXOR = maxXORHelper(input[i]);
			mXOR = maxVal(currentXOR, mXOR);
		}

		return mXOR;
	}

	void clear() {
		eraseAll(root);
	}
	
};

int main(int argc, char const *argv[])
{
	
	return 0;
}