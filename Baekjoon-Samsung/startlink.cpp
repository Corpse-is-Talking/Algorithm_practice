#include<iostream>
#include<queue>
using namespace std;
int t_map[21][21] = { 0, };

int N = 0;
int cur_min = 9999;
bool findnum(int num, const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == num)
			return true;
	}
	return false;
}
int getsum( vector<int>& vec)
{
	int a_size = vec.size();
	int cur_sum = 0;
	vector<vector<bool>> is_visited(a_size,vector< bool>(a_size,false));
	for (int i = 0; i <vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (is_visited[i][j] == false && i != j)
			{
				int correl = (t_map[vec[i]][vec[j]] + t_map[vec[j]][vec[i]]);
				cur_sum += correl;
				is_visited[i][j] = true;
				is_visited[j][i] = true;
			}
		}
	}
	return cur_sum;

}
void doDFS(int start,  vector<int> vec)
{
	vec.push_back(start);
	if (vec.size() == N / 2)
	{
		int h_sum = getsum(vec);
		vector<int> vec2;
		for (int i = 1; i <= N; i++)
		{
			if (!findnum(i, vec))
				vec2.push_back(i);
			
		}
	
	
		int h2_sum =getsum(vec2);
		if (abs(h2_sum - h_sum) < cur_min)
			cur_min = abs(h2_sum - h_sum);
		return;
	}

	for (int i = start + 1; i <= N ; i++)
	{
		if (findnum(i,vec))
			continue;
		else
			doDFS(i,  vec);
	}
	return;

}
int main()
{
	
	int s_num = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input = 0;
			cin >> input;
			t_map[i+1][j+1] = input;
		}
	}
	vector < int> vec;
	for(int i=1; i<=N; i++)
		doDFS(i, vec);
	cout << cur_min;
	
	return 0;
}