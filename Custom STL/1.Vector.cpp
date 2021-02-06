#include <iostream>
using namespace std;

template <typename T>
class VectorClass
{
	// arr is the integer pointer
	// which stores the address of our vector
	T *arr;

	// capacity is the total storage
	// capacity of the vector
	int capacity;

	// current is the number of elemets present in the vector
	int current;

	// Default constructor to initialise
	public: 

	VectorClass() {
		// an initial capacity of 1 element and
		// allocating storage using dynamic allocation
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	// function to add element at last
	void push(T data) {
		// if the number of elements is equal to the
	        // capacity, that means we don't have space to
	        // accommodate more elements. We need to double the
	        // capacity
		if (current == capacity) {
			T *temp = new T[2 * capacity];

			// copying all old elements
			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			// deleting previous array
			delete[] arr;
			arr = temp;
			capacity = capacity * 2;
		}

		// Inserting data
		arr[current++] = data;
	}

	// function to delete element from last
	void pop() {
		current--;
	}

	// function to return vector size
	int size() {
		return current;
	}

	// function to return vector capacity
	int getCapacity() {
		return capacity;
	}

	// removes all element
	void clear() {
		current = 0;
	}

	// display all elements
	void display() {
		for (int i = 0; i < current; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	VectorClass <int> myVector;

	myVector.push(52);
	myVector.push(22);
	myVector.push(13);
	myVector.push(27);
	myVector.push(72);

	cout << "Vector size is: " << myVector.size() << endl;
	cout << "Vector capacity is: " << myVector.getCapacity() << endl;

	cout << "Vector elements" << endl;
	myVector.display();

	myVector.pop();
	myVector.pop();

	cout << "Vector size is: " << myVector.size() << endl;
	cout << "Vector capacity is: " << myVector.getCapacity() << endl;

	cout << "Vector elements" << endl;
	myVector.display();

	return 0;
}