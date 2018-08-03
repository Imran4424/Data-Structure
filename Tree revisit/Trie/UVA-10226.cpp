#include <iostream>
#include <cstring>
using namespace std;

class Trie
{
	private: struct node
	{
		bool endmark;
		int count;
		char key[15];
		node* next[37+1];

		node()
		{
			endmark = false;
			count = 0;

			for (int i = 0; i < 37; ++i)
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

	private: ShowSorted(node* travel, int total)
	{
		for (int i = 0; i < 37; ++i)
		{
			if (travel -> endmark && i == 0)
			{
				double temp = (travel -> count * 100) / (double)total

				cout<<travel -> key<<" "<<fixed<<setprecision(4)<<temp<<endl;
			}

			if (travel -> next[i] != NULL)
			{
				ShowSorted(travel -> next[i]);
			}
		}
	}

	public: void Display(int total)
	{
		ShowSorted(root,total);
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
	int test;
	cin>>test;
	
	return 0;
}