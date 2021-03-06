#include <iostream>
using namespace std;

class Link_list
{

	public: struct node
	{
		int data;
		node* nextAddress;
	};

	node* head;

	public: Link_list()
	{
		head = NULL;
	}

	public: void insert_node_at_the_end(int value)
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

	public: void insert_node_at_the_begin(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> nextAddress = head;

		head = temp;
	}

	public: void delete_at_the_end()
	{
		if (head == NULL)
		{
			cout<<"Underflow, can't delete"<<endl;

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

	public: void delete_at_the_begin()
	{
		if (head == NULL)
		{
			cout<<"Underflow, can't delete"<<endl;

			return;
		}

		head = head -> nextAddress;
	}

	public: void Reverse()
	{

		node *previous,*current,*next;

		previous = NULL;
		current = head;

		while(current != NULL)
		{
			next = current -> nextAddress;

			current -> nextAddress = previous;

			previous = current;
			current = next;
		}

		head = previous;
	}

	public: void ReverseRecursion(node* travel)
	{
		if (travel -> nextAddress == NULL)
		{
			head = travel;

			return;
		}

		ReverseRecursion(travel -> nextAddress);

		node* temp = travel -> nextAddress;

		temp -> nextAddress = travel;

		travel -> nextAddress = NULL;

	}

	public: void ReverseRecursionHandler()
	{
		node* travel = head;

		ReverseRecursion(travel);
	}

	public: void display()
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

	public: void displayRecursion(node* travel)
	{
		if (travel == NULL)
		{
			return;
		}


		cout<<travel -> data<<" ";

		displayRecursion(travel -> nextAddress);
	}

	public: void displayReverseRecursion(node* travel)
	{
		if (travel == NULL)
		{
			return;
		}

		displayReverseRecursion(travel -> nextAddress);

		cout<<travel -> data<<" ";
	}

	public: void displayRecursionHandler(bool status)
	{
		node* travel = head;

		if (status)
		{
			displayRecursion(travel);
		}
		else
		{
			displayReverseRecursion(travel);
		}
	}

};




int main(int argc, char const *argv[])
{
	Link_list obj;

	cout<<"how many node's you want to insert"<<endl;

	int n;
	cin>>n;

	cout<<"enter the value of the node"<<endl;
	
	for (int i = 0; i < n; ++i)
	{

		int temp_val;
		cin>>temp_val;

		//obj.insert_node_at_the_end(temp_val);
		obj.insert_node_at_the_begin(temp_val);
	}


	// display the node

	obj.display();

	//Revering the list iteartive method
	cout<<"Reversed linklist: ";

	obj.ReverseRecursionHandler();

	obj.display();

	// delete nodes

	cout<<"how many nodes you wnat to delete"<<endl;

	int num;
	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		obj.delete_at_the_begin();
	}

	obj.display();

	return 0;
}