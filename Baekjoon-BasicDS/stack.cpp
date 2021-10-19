	#include<iostream>
	#include<vector>

	using namespace std;
	class box
	{
	public:
		int first = -1;
		int last = -1;
		vector<int> con;
		box() :con(10001, 0)
		{}
		void push(int input)
		{
		
			first++;
			con[first] = input;

		}
		int size()
		{
			return first - last;
		}
		int isempty()
		{
			if (first - last == 0)
				return true;
			else
				return false;
		}
		void pop()
		{
			first--;
		}
		int front()
		{
			return con[first];
		}
		//Create vec

	};
	int main()
	{
		box b;
		int N = 0;
		cin >> N;
		vector<int> vec(N, 0);
		for (int i = 0; i < N; i++)
		{
			string input;
			cin >> input;
			int n = -1;
			if (input == "push")
			{
				cin >> n;
				b.push(n);

			}

			else if (input == "pop")
			{
				if (b.isempty() == true)
				{
					cout << -1 << endl;
				}
				else
				{
					cout << b.front() << endl;
					b.pop();
				}
			}
			else if (input == "size")
			{
				cout << b.size() << endl;
			}
			else if (input == "empty")
			{
				if (b.isempty() == true)
					cout << 1 << endl;
				else
					cout << 0 << endl;
			}
			else if (input == "top")
			{
				if (b.isempty() == true)
					cout << -1 << endl;
				else
					cout << b.front() << endl;
			}
			else continue;

		}
		//No need to push_back just create index that can indicate where current vectore is..



	}