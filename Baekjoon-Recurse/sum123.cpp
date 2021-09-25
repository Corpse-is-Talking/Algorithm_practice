#include<iostream>
using namespace std;
int memory[11];
int findWay(int n)
{
	if (memory[n] != 0)
		return memory[n];
	if (n == 1)
	{
		memory[1] = 1;
		return 1;
	}

	if (n == 2)
	{
		memory[2] = 2;
		return 2;
	}
	if (n == 3)
	{
		memory[3] = 4;
		return 4;
	}
	else 
	{
		memory[n]= findWay(n - 1) + findWay(n - 2) + findWay(n - 3);
		return memory[n];
	}
}
int main()
{
	int repeat = 0;
	cin >> repeat;
	for (int i = 0; i < repeat; i++)
	{
		int N = 0;
		cin >> N;
		int res = findWay(N);
		cout << res<<'\n';
	}

	return 0;
}