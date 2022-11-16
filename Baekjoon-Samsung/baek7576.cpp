#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool is_visited[1000][1000] = { false, };
int tomato[1000][1000] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void printtomato(int m, int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			cout << tomato[j][i]<<" ";


		}
		cout << endl;
	}
}
int main()
{
	queue<pair<int,int>> que;
	int M = 0;
	int N = 0;
	cin >> M >> N;
	int minuscount = 0;
	int pluscount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 1)
			{
				que.push(make_pair(j, i));
				is_visited[j][i] = true;
				pluscount++;

			}
			if (temp == -1)
			{
				minuscount++;
			}


			tomato[j][i] = temp;
		}
	}
	int day = 0;

	if (pluscount + minuscount == M * N)
	{
		cout << day;
		return 0;
	}


	while (!que.empty())
	{
		int qsize = que.size();
		for (int t = 0; t < qsize; t++)
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			//printtomato(M, N);
			for (int i = 0; i < 4; i++)
			{
				int cur_x = x + dx[i];
				int cur_y = y + dy[i];
				if (cur_x < M && cur_x >= 0 && cur_y < N && cur_y >= 0 && is_visited[cur_x][cur_y] == false && tomato[cur_x][cur_y] == 0)
				{
					que.push(make_pair(cur_x, cur_y));
					tomato[cur_x][cur_y] = 1;
					is_visited[cur_x][cur_y] = true;
					pluscount++;
				}
			}
			
			
		}

		day++;
		if (pluscount + minuscount == M * N)
			break;
		
			
	}
	if (pluscount + minuscount < M * N)
		cout << -1;
	else
		cout << day;


	return 0;
}