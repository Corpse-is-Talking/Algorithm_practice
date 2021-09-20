#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int info[1000][1000] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	int N = 0, M = 0;
	cin >> M >> N;
	queue<pair<int,int>> que;
	queue<pair<int, int>> zero_que;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cur_info = 0;
			cin >> cur_info;
			info[i][j] = cur_info;
			if (cur_info == 1)
				que.push(make_pair(i, j));
			if (cur_info == 0)
				zero_que.push(make_pair(i, j));
				
		}
	}
	int day = 0;
	while (!que.empty())
	{

		vector<int> x;
		vector<int> y;
		while (!que.empty())
		{
			int cur_x = que.front().first;
			int cur_y = que.front().second;
			x.push_back(cur_x);
			y.push_back(cur_y);
			que.pop();
		}
		for (int i = 0; i < x.size(); i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int new_x = x[i] + dx[k];
				int new_y = y[i] + dy[k];
				if (info[new_x][new_y] == -1 || info[new_x][new_y] == 1 || 0 > new_x || 0 > new_y || new_x >= N || new_y >= M)
					continue;
				info[new_x][new_y] = 1;
				que.push(make_pair(new_x, new_y));
				zero_que.pop();

			}
		}
		day++;
	}
	if (zero_que.size() > 0)
		cout << -1;
	else
		cout << day - 1;





	return 0;
}