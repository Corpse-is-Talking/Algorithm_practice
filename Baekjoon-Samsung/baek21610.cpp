#include <vector>
#include <iostream>
using namespace std;
int dir_x[] = {0,0,-1,-1,-1,0,1,1,1};
int dir_y[] = {0,-1,-1,0,1,1,1,0,-1};
int diag_x[] = { 1,1,-1,-1 };
int diag_y[] = { -1,1,-1,1 };
void constructcloud(vector<vector<int>>& vec, vector<int>& cur_cloud_x, vector<int>& cur_cloud_y, vector<int> temp_cloud_x, vector<int> temp_cloud_y, int N)
{
	cur_cloud_x.clear();
	cur_cloud_y.clear();
	vector<int> temp_x;
	vector<int> temp_y;
	for (int i = 0; i < temp_cloud_x.size(); i++)
	{
		temp_x.push_back(temp_cloud_x[i]);
		temp_y.push_back(temp_cloud_y[i]);

	}
	for (int i = 1; i <= N; i++)
	{

		for (int j = 1; j <=N; j++)
		{
			if (vec[i][j] >= 2)
			{
				bool flag = true;
				for (int k = 0; k < temp_x.size(); k++)
				{
					if (i == temp_x[k] && j == temp_y[k])
					{
						flag = false;
						break;
					
					}

				}
				if (flag==true)
				{
					vec[i][j] -= 2;
					cur_cloud_x.push_back(i);
					cur_cloud_y.push_back(j);
				}
			}


		}
	}


}
void rain(vector<vector<int>>& vec, vector<int> &cur_cloud_x, vector<int> & cur_cloud_y,int N)
{
	
	for (int i = 0; i < cur_cloud_x.size(); i++)
	{
		vec[cur_cloud_x[i]][cur_cloud_y[i]] += 1;
	}
	vector<int> info;
	for (int i = 0; i < cur_cloud_x.size(); i++)
	{
		int cur_x = cur_cloud_x[i];
		int cur_y = cur_cloud_y[i];
		int cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			int n_x =cur_x+ diag_x[j];
			int n_y=cur_y + diag_y[j];
			if (n_x <= N && n_x >= 1 && n_y <= N && n_y >= 1&&vec[n_x][n_y]>0)
			{
				cnt += 1;
			}
			else
				continue;

		}
		info.push_back(cnt);
	}
	for (int i = 0; i < cur_cloud_x.size(); i++)
	{
		vec[cur_cloud_x[i]][cur_cloud_y[i]] += info[i];

	}


}
int movedir_x(int cur_x,  int dir, int s, int N)
{
	while (s >0)
	{
		cur_x += dir_x[dir];
		if (cur_x == 0)
			cur_x = N;
		if (cur_x == N + 1)
			cur_x = 1;
		s--;
	}
	return cur_x;
}
int movedir_y(int cur_y, int dir, int s, int N)
{ 
	while (s >0)
	{
		cur_y += dir_y[dir];
		if (cur_y == 0)
			cur_y = N;
		if (cur_y == N + 1)
			cur_y = 1;
		s--;
	}
	return cur_y;
}
int main()
{

	vector<vector<int>> vec(51, vector<int>(51, 0));
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int temp;
			cin >> temp;
			vec[i][j] = temp;
		}
	}
	vector<pair<int, int>> order;
	for (int i = 0; i < M; i++)
	{
		int dir, s;
		cin >> dir >> s;
		order.push_back(make_pair(dir, s));
	}
	vector<int> cur_cloud_x = {N,N,N-1,N-1};
	vector<int> cur_cloud_y = { 1,2,1,2 };
	for (int i = 0; i < M; i++)
	{
		int cur_dir = order[i].first;
		int cur_s = order[i].second;
		//move cloud
		for (int i = 0; i < cur_cloud_x.size(); i++)
		{
			cur_cloud_x[i] = movedir_x(cur_cloud_x[i], cur_dir, cur_s, N);
			cur_cloud_y[i]= movedir_y(cur_cloud_y[i], cur_dir, cur_s, N);
		}
		rain(vec, cur_cloud_x, cur_cloud_y,N);

		constructcloud(vec, cur_cloud_x, cur_cloud_y,cur_cloud_x,cur_cloud_y, N);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer += vec[i][j];

		}

	}
	cout << answer;


}