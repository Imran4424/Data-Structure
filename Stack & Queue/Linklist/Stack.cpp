class Stack
{
	public: struct node
	{
		int data;
		node* nextAddress;
	};

	node* head;

	public: Stack()
	{
		head = NULL;
	}
	
};


int main(int argc, char const *argv[])
{
	Stack obj = new Stack();
	
	return 0;
}