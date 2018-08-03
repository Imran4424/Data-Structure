#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef long long int lli;

class Trie
{
	private: struct node
	{
		bool endmark;
		int count;
		string key;
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

	private: void MakeLower(string str)
	{
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
	}

	public: void Insertion(string str)
	{
		string original_key = str;

		MakeLower(str);

		node* travel = root;

		for (int i = 0; i < str.size(); ++i)
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

		travel -> key = original_key;
	}

	public: bool Search(string str)
	{
		MakeLower(str);

		node* travel = root;

		for (int i = 0; i < str.size(); ++i)
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

	private: void ShowSorted(node* travel, int total)
	{
		for (int i = 0; i < 37; ++i)
		{
			if (travel -> endmark && i == 0)
			{
				double temp = (travel -> count * 100.0) / total;

				cout<<travel -> key<<" "<<fixed<<setprecision(4)<<temp<<endl;
			}

			if (travel -> next[i] != NULL)
			{
				ShowSorted(travel -> next[i], total);
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

	getchar();
    getchar();

	while(test--)
	{
		Trie lists;

		string tree;
        lli total = 0;
        
        while(true)
        {
            getline(cin,tree);

            if(tree.empty()){
                break;
            }

			lists.Insertion(tree);

			total++;
		}

		lists.Display(total);

		if (test)
		{
			cout<<endl;

			lists.Clear();
			total = 0;
		}
	}
	
	return 0;
}