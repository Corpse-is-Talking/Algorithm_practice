#include <iostream>
#include <vector>
#include<queue>
#include<string>
#include <cmath>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map_info[1000][1000] = { 0, };
int range[1000][1000][2] = { 0, };
bool is_visited[1000][1000][2] = { false, };

int doBFS(int N, int M)
{
	queue<pair<int, pair<int, int>>> que;
	que.push(make_pair(0,make_pair(0, 0)));
	range[0][0][0] = 1;
	while (!que.empty())
	{
		int didvisit = que.front().first;
		int cur_x = que.front().second.first;
		int cur_y = que.front().second.second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			if (didvisit == 1)
			{
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M || map_info[nx][ny] == 1)
					continue;

				int check = range[nx][ny][1];
				int update = range[cur_x][cur_y][1] + 1;
				if (is_visited[nx][ny][1] == false)
				{
					range[nx][ny][1] = update;
					is_visited[nx][ny][1] = true;
					que.push(make_pair(1, make_pair(nx, ny)));
					continue;

				}

				if (is_visited[nx][ny][1] == true)
				{
					if (check > update)
					{
						range[nx][ny][1] = update;
						que.push(make_pair(1, make_pair(nx, ny)));
					}
					else
					{
						continue;
					}

				}
			}
			else if (didvisit == 0)
			{
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M || is_visited[nx][ny][0] == true)
					continue;

				if (map_info[nx][ny] == 0)
				{
					range[nx][ny][0] = range[cur_x][cur_y][0] + 1;
					is_visited[nx][ny][0] = true;
					que.push(make_pair(0, make_pair(nx, ny)));

				}
				if (map_info[nx][ny] == 1)
				{
					range[nx][ny][1] = range[cur_x][cur_y][0] + 1;
					is_visited[nx][ny][1] = true;
					que.push(make_pair(1, make_pair(nx, ny)));
				}

			}
		}
	}

	if (range[N - 1][M - 1][1] == 0 && range[N - 1][M - 1][0] == 0)
		return -1;
	if (range[N - 1][M - 1][1] == 0 || range[N - 1][M - 1][0] == 0)
		return max(range[N - 1][M - 1][1], range[N - 1][M - 1][0]);
	else return min(range[N - 1][M - 1][1], range[N - 1][M - 1][0]);

}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map_info[i][j] = str[j]-'0';
		}
	}
	int cur_max = 0;
	int bfs = doBFS(N, M);
	if (bfs == 0) cout << -1;
	else cout << bfs;
	
	return 0;
	

}