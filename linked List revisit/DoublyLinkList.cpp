#include <iostream>
using namespace std;

class DoublyLinkList
{
	private: struct node
	{
		int data;
		node* prevAddress;
		node* nextAddress;
	};

	private: node* head;

	public: DoublyLinkList()
	{
		head = NULL;
	}

	public: void InsertAtEnd(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> nextAddress = NULL;

		if (head == NULL)
		{
			temp -> prevAddress = NULL;

			head = temp;

			return;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		temp -> prevAddress = travel;
		travel -> nextAddress = temp;
	}

	public: void InsertAtBegin(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> prevAddress = NULL;

		if (head == NULL)
		{
			temp -> nextAddress = NULL;
			head = temp;

			return;
		}

		head -> prevAddress = temp;
		temp -> nextAddress = head;


		head = temp;

	}

	public: void DeleteAtEnd()
	{
		if (head == NULL)
		{
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

	public: void DeleteAtBegin()
	{
		if (head == NULL)
		{
			return;
		}
		else if (head -> nextAddress == NULL)
		{
			head = NULL;

			return;
		}

		head = head -> nextAddress;

		head -> prevAddress = NULL;
	}


	public: void ReverseIterative()
	{
		if (head == NULL)
		{
			return;
		}

		node *travel, *temp;

		travel = head;

		while(travel -> nextAddress != NULL)
		{
			temp = travel -> prevAddress;
			travel -> prevAddress = travel -> nextAddress;
			travel -> nextAddress = temp;

			travel = travel -> prevAddress;
		}

		temp = travel -> prevAddress;
		travel -> prevAddress = travel -> nextAddress;
		travel -> nextAddress = temp;

		head = travel;
	}

	public: void ReverseRecursion(node* travel)
	{
		if (travel -> nextAddress == NULL)
		{
			node* temp;

			temp = travel -> prevAddress;
			travel -> prevAddress = travel -> nextAddress;
			travel -> nextAddress = temp;

			head = travel;

			return;
		}

		ReverseRecursion(travel -> nextAddress);

		node* temp;

		temp = travel -> prevAddress;
		travel -> prevAddress = travel -> nextAddress;
		travel -> nextAddress = temp;
	}

	public: void ReverseRecursionHandler()
	{
		node* travel = head;

		ReverseRecursion(travel);
	}

	public: void Clear()
	{
		head = NULL;
	}

	public: void Display()
	{
		if (head == NULL)
		{
			cout<<"there's nothing to Display"<<endl;

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
	DoublyLinkList obj;

	cout<<"how many values you want to inset"<<endl;

	int num;
	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		int temp_val;
		cin>>temp_val;

		//obj.InsertAtEnd(temp_val);
		obj.InsertAtBegin(temp_val);
	}

	// Display

	obj.Display();

	//obj.ReverseRecursionHandler();
	obj.ReverseIterative();

	cout<<"Reversed Link List is: ";

	obj.Display();

	cout<<"How many values you want to delete"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		obj.DeleteAtBegin();
	}

	// Display

	obj.Display();	

	return 0;
}