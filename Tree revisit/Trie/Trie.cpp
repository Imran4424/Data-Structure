#include <iostream>
#include <string>
using namespace std;

class Trie
{
	private: struct node
	{
		bool endmark;
		char key[15];
		int count;

		node* next[38+1];

		node()
		{
			endmark = false;
			count = 0;

			for (int i = 0; i < 39; ++i)
			{
				next[i] = NULL;
			}
		}
	};

	private: node* root = new node();

	private: void MakeLower(char* str, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
	}

	public: void Insertion(char* str, int length)
	{
		MakeLower(str, length);

		node* travel = root;

		for (int i = 0; i < length; ++i)
		{
			int id;

			if (str[i] == '.')
			{
				id = 36;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				id = str[i] - 22;
			}
			else
			{
				id = str[i] - 'a';
			}


			if (travel -> next[id] == NULL)
			{
				travel -> next[id] = new node();
			}

			travel = travel -> next[id];	
		}

		travel -> endmark = true;

		travel -> count = travel -> count + 1;

		strcpy(travel -> key, str);
	}

	public: bool Search(char* str, int length)
	{
		MakeLower(str, length);

		node* travel = root;

		for (int i = 0; i < length; ++i)
		{
			int id;

			if (str[i] == '.')
			{
				id = 36;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				id = str[i] - 22;
			}
			else
			{
				id = str[i] - 'a';
			}


			if (travel -> next[id] == NULL)
			{
				return false;
			}

			travel = travel -> next[id];
		}

		return travel -> endmark;
	}

	private: void del(node* travel)
	{
		for (int i = 0; i < 27; ++i)
		{
			if (travel -> next[i])
			{
				del(travel -> next[i]);
			}
		}

		delete(travel);		
	}


	public: void Clear()
	{
		del(root);
	}

	private: ShowSorted(node* travel)
	{
		for (int i = 0; i < 37; ++i)
		{
			if (travel -> endmark && i == 0)
			{
				cout<<travel -> key<<" "<<travel -> count<<endl;
			}

			if (travel -> next[i] != NULL)
			{
				ShowSorted(travel -> next[i]);
			}
		}
	}

	public: void Display()
	{
		ShowSorted(root);
	}

	public: bool IsEmpty()
	{
		node* travel = root;

		for (int i = 0; i < 37; ++i)
		{
			if (travel -> next[i] != NULL)
			{
				return false;
			}
		}

		return true;
	}
};


int main(int argc, char const *argv[])
{
	Trie obj;

	cout<<"how many words you want to insert"<<endl;

	int num;
	cin>>num;

	cout<<"enter the words"<<endl;

	for (int i = 0; i < num; ++i)
	{
		char str[15];
		cin>>str;

		int length = strlen(str);

		obj.Insertion(str, length);
	}

	obj.Display();

	cout<<"how many words you want to Search"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		
		char se_str[15];
		cin>>se_str;

		int length = strlen(se_str);


		bool status = obj.Search(se_str, length);

		if (status)
		{
			cout<<"the word is present in the tree"<<endl;
		}
		else
		{
			cout<<"The word is not present in the tree"<<endl;
		}
	}
	
	return 0;
}