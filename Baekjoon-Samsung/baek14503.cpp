#include <vector>
#include <iostream>
#include<queue>
using namespace std;
int r_map[50][50] = { 0, };
int is_visited[50][50] = { 0, };
int updatedirection(int cur_direction)
{
	int next_direction = (cur_direction - 1);
	if (next_direction < 0)
		next_direction = 3;
	return (next_direction);
}
bool checkdir(int cur_direction, int cur_x, int cur_y, int N, int M)
{
	if (cur_x + 1 < N && is_visited[cur_x + 1][cur_y] == 0 && r_map[cur_x+1][cur_y]==0)
		return false;
	if (cur_x - 1 >= 0 && is_visited[cur_x - 1][cur_y] == 0 && r_map[cur_x - 1][cur_y] == 0)
		return false;
	if (cur_y + 1 < M && is_visited[cur_x][cur_y + 1] == 0 && r_map[cur_x][cur_y + 1] == 0)
		return false;
	if (cur_y - 1 >= 0 && is_visited[cur_x ][cur_y-1] == 0 && r_map[cur_x ][cur_y-1] == 0)
		return false;


	return true;
}
int main()
{
	int N, M;
	cin >> N >> M;
	int r, c, d; 
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			r_map[i][j] = temp;
		}
	}
	//left, 
	queue<pair<int, int>> que;
	que.push(make_pair(r, c));
	is_visited[r][c] = 1;
	int count = 1;
	int cur_direction = d;
	while (!que.empty())
	{
		int cur_x=que.front().first;
		int cur_y = que.front().second;
		
		que.pop();
		int next_x = 0;
		int next_y = 0;
		int back_x = 0;
		int back_y = 0;
		if (cur_direction == 0)
		{
			next_x = cur_x;
			next_y = cur_y - 1;
			back_x = cur_x +1;
			back_y = cur_y;
		}
		if (cur_direction == 1)
		{
			next_x = cur_x-1;
			next_y = cur_y ;
			back_x = cur_x ;
			back_y = cur_y-1;
		}
		if (cur_direction == 2)
		{
			next_x = cur_x;
			next_y = cur_y +1;
			back_x = cur_x -1;
			back_y = cur_y;

		}
		if (cur_direction == 3)
		{
			next_x = cur_x+1;
			next_y = cur_y;
			back_x = cur_x ;
			back_y = cur_y+1;
		}


		bool cantclean = checkdir(cur_direction, cur_x, cur_y,N,M);
		if ( cantclean &&((back_x < 0 || back_y < 0 || back_x >= N || back_y >= M)||r_map[back_x][back_y]==1))
			continue;
		else if(cantclean && r_map[back_x][back_y] == 0)
		{
			que.push(make_pair(back_x, back_y));
			//is_visited[back_x][back_y] = 1;
			continue;
		}

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && r_map[next_x][next_y] == 0 &&is_visited[next_x][next_y]==0)
		{
			cur_direction = updatedirection(cur_direction);
			que.push(make_pair(next_x, next_y));
			is_visited[next_x][next_y] = 1;
			count++;
			continue;
		}
		else
		{
			cur_direction = updatedirection(cur_direction);
			que.push(make_pair(cur_x, cur_y));
			continue;

		}
		



		
	}

	cout << count;


	return 0;
}