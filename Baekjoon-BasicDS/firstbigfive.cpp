#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int cur_max = -1;
void getnum(int num, int idx, vector<int> & vec,vector<pair<int,int>> &check)
{

	if (idx == check.size() - 1)
	{
		check[idx].first = -1;
		check[idx].second = -1;
		return;
	}
	if (vec[idx] >= vec[idx + 1] && check[idx+1].second == -1)
	{
		check[idx].first = -1;
		check[idx].second = -1;
		return;
	}
	if (vec[idx] > vec[idx + 1])
	{
		if (cur_max <= vec[idx])
		{
			check[idx].first = -1;
			check[idx].second = -1;
			return;
		}

		int cur_idx = idx + 1;
		while (cur_idx < check.size())
		{
			if (vec[cur_idx] > vec[idx])
			{
				check[idx].first = cur_idx;
				check[idx].second = vec[cur_idx];
				break;
			}
			else
			{
				cur_idx = check[cur_idx].first;
			}

		}
			
		return;
	}

	if (vec[idx] < vec[idx + 1] )
	{
		check[idx].second = vec[idx+1];
		check[idx].first = idx+1;
		return;
	}
	if (vec[idx] == vec[idx + 1])
	{
		check[idx].first = check[idx + 1].first;
		check[idx].second = check[idx + 1].second;
		return;
	}


}
int main()
{
	int N = 0;
	cin >> N;
	vector<int> vec(1000000);
	for (int i = 0; i < N; i++)
	{
		int input=0;
		cin >> input;
		vec[i] = input;
	}
	vector<pair<int, int>> check(N);
	for (int i = N-1; i >=0; i--)
	{
		getnum(vec[i], i,vec,check);
		if (vec[i] > cur_max)
			cur_max = vec[i];

	}
	for (int i = 0; i < N; i++)
	{
		cout << check[i].second << " ";
	}


}