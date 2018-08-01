#include <iostream>
#include <string>
using namespace std;

template <class anyType>
class Stack
{
	private: struct node
	{
		anyType data;
		node* nextAddress;
	};

	private: node* head;

	public: Stack()
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

	public: void Push(anyType value)
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
			cout<<"Stack Underflow"<<endl;

			return;
		}
		else if (head -> nextAddress == NULL)
		{
			head = NULL;

			return;
		}

		node* travel = head;

		while(travel -> nextAddress -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		travel -> nextAddress = NULL;
	}

	public: anyType Top()
	{
		if (head == NULL)
		{
			cout<<"Stack is empty"<<endl;

			return 0;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}
	
};


struct Student
{
	int id;
	string name;
};

int main(int argc, char const *argv[])
{
	Stack <Student> obj;

	cout<<"how many Student you want to Push"<<endl;

	int num;
	cin>>num;

	cout<<"input Student information"<<endl;

	for (int i = 0; i < num; ++i)
	{
		int temp_id;
		string temp_name;
		cin>>temp_id>>temp_name;

		Student temp;

		temp.id = temp_id;
		temp.name = temp_name;

		obj.Push(temp_val);
	}

	obj.Display();

	cout<<"Top: "<<obj.Top()<<endl;


	cout<<"how many values you want to Pop"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		obj.Pop();
	}

	obj.Display();

	cout<<"Top: "<<obj.Top()<<endl;

	return 0;
}