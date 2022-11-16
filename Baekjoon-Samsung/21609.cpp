#include <iostream>
#include <vector>
#include<queue>
int N, M;
using namespace std;
int dir_x[] = { 1,0,-1,0 };
int dir_y[] = { 0,1,0,-1 };
void doBFS(int start_x, int start_y, vector<vector<int>> cur_map, vector<vector<int>> &is_visited, vector<int> &cur_info, vector<pair<int,int>> &cur_answer)
{
	if (cur_map[start_x][start_y] == -1 || cur_map[start_x][start_y] == 0 || is_visited[start_x][start_y] == true||cur_map[start_x][start_y]==-2)
		return;
	queue<pair<int, int>> que;
	 // 매개변수로 넘기는게날듯
	que.push(make_pair(start_x, start_y));
	int block_count = 1;
	int rainbow_num = 0;
	int standard_x = start_x;
	int standard_y = start_y;
	int block_max = cur_map[start_x][start_y];
	is_visited[start_x][start_y] = true;
	vector<pair<int, int>> vec;
	vec.push_back(make_pair(start_x, start_y));

	while (!que.empty())
	{
		int cur_x = que.front().first;
		int cur_y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_x = cur_x + dir_x[i];
			int n_y = cur_y + dir_y[i];
			if (n_x >= N || n_x < 0 || n_y >= N || n_y < 0 || is_visited[n_x][n_y] == true || cur_map[start_x][start_y] == -2|| cur_map[start_x][start_y] == -1)
				continue;
			else
			{
				is_visited[n_x][n_y] = true;
				if (cur_map[n_x][n_y] == 0)
				{
					rainbow_num += 1;
					block_count += 1;
					que.push(make_pair(n_x, n_y));
					vec.push_back(make_pair(n_x, n_y));
					continue;
					

				}
				if (cur_map[n_x][n_y] == block_max)
				{
					block_count += 1;
					if (n_x < standard_x)
					{
						standard_x = n_x;
					}
					else if (n_x == standard_x)
					{
						if (n_y < standard_y)
							standard_y = n_y;
					}
					que.push(make_pair(n_x, n_y));
					vec.push_back(make_pair(n_x, n_y));
					continue;

				}

			}
		}
	}
	if (vec.size() == 1)
		return;
	vector<int> info;
	info.push_back(block_count);
	info.push_back(rainbow_num);
	info.push_back(standard_x);
	info.push_back(standard_y);
	if (info[0] > cur_info[0])
	{
		cur_info = info;
		cur_answer = vec;
		return;
	}
	if (info[0] == cur_info[0])
	{
		if (info[1] > cur_info[1])
		{
			cur_info = info;
			cur_answer = vec;
			return;
		}
		if (info[1] == cur_info[1])
		{
			if (info[2] > cur_info[2])
			{
				cur_info = info;
				cur_answer = vec;
				return;
			}


			if (info[2] == cur_info[2])
			{
				if (info[3] > cur_info[3])
				{
					cur_info = info;
					cur_answer = vec;
					return;
				}
			}
			}

		}

	}
void erasegroup(vector<vector<int>>& cur_map, vector<pair<int, int>> cur_answer)
{
	for (int i = 0; i < cur_answer.size(); i++)
	{
		int cur_x = cur_answer[i].first;
		int cur_y = cur_answer[i].second;
		cur_map[cur_x][cur_y] = -2;
	}

}
void rotate(vector<vector<int>>& cur_map)
{
	vector<vector<int>> temp_map=cur_map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp_map[i][j] = cur_map[j][N-1 - i];

		}

	}
	cur_map = temp_map;

}
void findbestgroup(vector<vector<int>> cur_map, vector<pair<int, int>>& group)
{
	vector<int> cur_info;
	cur_info.push_back(0);
	cur_info.push_back(0);
	cur_info.push_back(0);
	cur_info.push_back(0);
	vector<pair<int, int>> cur_answer;
	vector<vector<int>> is_visited(N, vector<int>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			doBFS(i, j, cur_map, is_visited,cur_info,cur_answer);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
						is_visited[i][j] = false;
				}
			}
		}
	}
	group = cur_answer;
}
void gravity(vector<vector<int>>& cur_map)
{
	for (int i = N-1; i >= 0; i--)
	{
		for (int j = N-1; j >= 0; j--)
		{
			if (cur_map[i][j] == -1)
				continue;
			int cur_x = i;
			int cur_y = j;
			int tomove = cur_map[i][j];
			while (cur_x < N - 1)
			{
				cur_x += 1;
				if (cur_map[cur_x][cur_y] != -2)
				{
					cur_x -= 1;
					break;
				}
			}
			if (cur_x > i)
			{
				cur_map[cur_x][cur_y] = tomove;
				cur_map[i][j] = -2;
			}

			if(cur_x==i)
				cur_map[cur_x][cur_y] = tomove;



		}
	}
}
int main()
{

	
	cin >> N >> M;
	vector<vector<int>> vec(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			vec[i][j] = temp;
		}
	}

	int cur_score = 0;

	while (true)
	{
		vector<pair<int, int>> group;
		findbestgroup(vec, group);
		//cout << group.size();
		if (group.size() <= 1)
			break;
		cur_score += (group.size() * group.size());
		erasegroup(vec, group);
		gravity(vec);
		rotate(vec);
		gravity(vec);
	}
	
	
	cout << cur_score;
	return 0;
}