#include <iostream>
using namespace std;


class Queue
{
		private: struct node
	{
		int data;
		node* nextAddress;
	};

	private: node* head;

	public: Queue()
	{
		head = NULL;
	}

	public: bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}

		return false;
	}

	public: int size()
	{
		if (head == NULL)
		{
			return 0;
		}

		int count = 0;

		node* travel = head;

		while(travel != NULL)
		{
			travel = travel -> nextAddress;

			count++;
		}

		return count;	
	}

	public: void Clear()
	{
		head = NULL;
	}

	public: void Push(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> nextAddress = NULL;

		if (head == NULL)
		{
			head = temp;

			return;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		travel -> nextAddress = temp;
	}

	public: void Pop()
	{
		if (head == NULL)
		{
			cout<<"Queue Underflow"<<endl;

			return;
		}

		head = head -> nextAddress;
	}

	public: int Rear()
	{
		if (head == NULL)
		{
			cout<<"Queue is empty"<<endl;

			return false;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}

	public: int Front()
	{
		if (head == NULL)
		{
			cout<<"Queue is empty"<<endl;

			return false;
		}

		return head -> data;
	}

	public: void Display()
	{
		if (head == NULL)
		{
			cout<<"there's nothing to display"<<endl;

			return;
		}

		node* travel = head;

		while(travel != NULL)
		{
			cout<<travel -> data<<" ";

			travel = travel -> nextAddress;
		}

		cout<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	Queue obj;

	cout<<"how many values you want to Push"<<endl;

	int num;
	cin>>num;

	cout<<"input the nodes values"<<endl;

	for (int i = 0; i < num; ++i)
	{
		int temp_val;
		cin>>temp_val;

		obj.Push(temp_val);
	}

	obj.Display();

	cout<<"Front: "<<obj.Front()<<endl;
	cout<<"Rear: "<<obj.Rear()<<endl;


	cout<<"how many values you want to Pop"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		obj.Pop();
	}

	obj.Display();

	cout<<"Front: "<<obj.Front()<<endl;
	cout<<"Rear: "<<obj.Rear()<<endl;

	return 0;
}