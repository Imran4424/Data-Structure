#include <iostream>
#include <string>
using namespace std;

template <class anyType>
class Queue
{
	private: struct node
	{
		anyType data;
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
			cout<<"Queue Underflow"<<endl;

			return;
		}

		head = head -> nextAddress;
	}

	public: anyType Rear()
	{
		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}

	public: anyType Front()
	{
		return head -> data;
	}

	public: void Display(anyType ar[])
	{
		if (head == NULL)
		{
			cout<<"there's nothing to display"<<endl;

			return;
		}

		node* travel = head;

		int i = 0;

		while(travel != NULL)
		{
			ar[i] = travel -> data;

			i++;

			travel = travel -> nextAddress;
		}

	}
	
};

struct Student
{
	int id;
	string name;
};

int main(int argc, char const *argv[])
{
	Queue <Student> obj;

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

		obj.Push(temp);
	}

	Student ar[obj.size()];

	obj.Display(ar);

	cout<<endl<<endl<<"Displaying:"<<endl;

	for (int i = 0; i < obj.size(); ++i)
	{
		cout<<ar[i].id<<endl;
		cout<<ar[i].name<<endl;
	}

	cout<<endl<<endl<<"Displaying Front:"<<endl;

	Student stu_front = obj.Front();
	Student stu_rear = obj.Rear();

	cout<<stu_front.id<<endl;
	cout<<stu_front.name<<endl;

	cout<<endl<<endl<<"Displaying Rear:"<<endl;

	cout<<stu_rear.id<<endl;
	cout<<stu_rear.name<<endl;		


	cout<<"how many values you want to Pop"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		obj.Pop();
	}

	cout<<endl<<endl<<"Displaying:"<<endl;

	for (int i = 0; i < obj.size(); ++i)
	{
		cout<<ar[i].id<<endl;
		cout<<ar[i].name<<endl;
	}

	cout<<endl<<endl<<"Displaying Front:"<<endl;

	stu_front = obj.Front();
	stu_rear = obj.Rear();

	cout<<stu_front.id<<endl;
	cout<<stu_front.name<<endl;

	cout<<endl<<endl<<"Displaying Rear:"<<endl;

	cout<<stu_rear.id<<endl;
	cout<<stu_rear.name<<endl;	

	return 0;
}