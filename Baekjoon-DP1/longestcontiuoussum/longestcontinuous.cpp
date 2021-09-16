#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n=0;
	cin >> n;
	vector<int> sum_save(100000,0);
	for (int i = 0; i < n; i++)
	{
		int input=0;
		cin >> input;
		sum_save[i] = input;
	}
	int cur_max = sum_save[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (sum_save[i] < sum_save[i + 1] + sum_save[i])
		{
			sum_save[i + 1] = sum_save[i] + sum_save[i + 1];
			if (sum_save[i + 1] > cur_max)
				cur_max = sum_save[i+1];

		}
		else
		{
			if (sum_save[i + 1] > cur_max)
				cur_max = sum_save[i + 1];
			if (sum_save[i] + sum_save[i + 1] < 0)
				
				sum_save[i + 1] = 0;
			else
				sum_save[i + 1] = sum_save[i] + sum_save[i + 1];

		}

	}
	cout << cur_max;



}