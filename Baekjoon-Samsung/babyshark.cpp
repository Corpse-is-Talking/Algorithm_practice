#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;
int N = 0;
int info[20][20] = { 0, };
bool is_visited[20][20] = {false, };
int shark_size = 2;		
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int,pair<int,int>>> que;
map<int,int> fish;
int iseatable()
{
	int f_num=0;
	for (int i = 1; i < shark_size; i++)
	{
		f_num += fish[i];
	}
	return f_num;
}
int doBFS()
{
	int cur_x = que.front().second.first;
	int cur_y = que.front().second.second;
	is_visited[cur_x][cur_y] = true;
	
	int ex = 0;
	int cur_count = 0;
	while (true)
	{
		if (iseatable() == 0)
			break;
		vector<pair<int, pair<int, int>>> mindis;
		while (!que.empty())
		{

			int cur_x = que.front().second.first;
			int cur_y = que.front().second.second;
			int c_count = que.front().first;
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];
				if (is_visited[nx][ny] == true || info[nx][ny] > shark_size || nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (info[nx][ny] == 0 || info[nx][ny] == shark_size)
				{
					is_visited[nx][ny] = true;
					que.push(make_pair(c_count + 1, make_pair(nx, ny)));
				}
				else if (info[nx][ny] < shark_size)
				{
					que.push(make_pair(c_count + 1, make_pair(nx, ny)));
					mindis.push_back(make_pair(c_count + 1, make_pair(nx, ny)));
					is_visited[nx][ny] = true;
				}
			}
		}
		if (mindis.size() == 0)
		{
			break;
		}
		sort(mindis.begin(), mindis.end());
		que.push(mindis[0]);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				is_visited[i][j] = false;
			}
		}
		is_visited[mindis[0].second.first][mindis[0].second.second] = true;
		
		fish[info[mindis[0].second.first][mindis[0].second.second]]-=1;
		info[mindis[0].second.first][mindis[0].second.second] = 0;
		cur_count = mindis[0].first;
		ex++;
		if (ex == shark_size)
		{
			ex = 0; 
			shark_size++;
		}
		




	}
	return cur_count;

}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			if (input == 9)
			{
				que.push(make_pair(0, make_pair(i, j)));
				info[i][j] = 0;
				continue;
			}
			if (input >= 1 && input <= 6)
			{
				fish[input]++;
				info[i][j] = input;
			}
			else info[i][j] = input;
		}
	}
	int res=doBFS();
	cout << res;
}