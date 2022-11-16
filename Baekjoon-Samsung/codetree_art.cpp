#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int N;
int dir_x[] = { 1,0,-1,0 };
int dir_y[] = { 0,1,0,-1 };
struct number
{
	int x;
	int y;
	int num;
	int group_num; //give random value..

};
void doBFS(vector<vector<int>> vec, vector<number> info[], vector<vector<bool>>& is_visited, int groupnum, int start_x, int start_y, vector<vector<int>>& groupmap)
{
	queue<pair<int, int>> que;
	que.push(make_pair(start_x, start_y));
	is_visited[start_x][start_y] = true;
	groupmap[start_x][start_y] = groupnum;
	info[groupnum].push_back(number{ start_x,start_y,vec[start_x][start_y],groupnum });
	while (!que.empty())
	{
		int cur_x = que.front().first;
		int cur_y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_x = cur_x + dir_x[i];
			int n_y = cur_y + dir_y[i];
			if (n_x >= N || n_y >= N || n_x < 0 || n_y < 0 || is_visited[n_x][n_y] == true || vec[n_x][n_y] != vec[start_x][start_y])
				continue;
			que.push(make_pair(n_x, n_y));
			info[groupnum].push_back(number{ n_x,n_y,vec[n_x][n_y],groupnum });
			is_visited[n_x][n_y] = true;
			groupmap[n_x][n_y] = groupnum;
		}

	}

}
int computescore(vector<number> g1, vector < number> g2, vector<vector<int>> groupmap)
{
	int g1num = g1[0].group_num;
	int g2num = g2[0].group_num;
	int num1 = g1[0].num;
	int num2 = g2[0].num;
	int g1size = g1.size();
	int g2size = g2.size();
	int nearnum = 0;
	for (auto k : g1)
	{
		int cur_x = k.x;
		int cur_y = k.y;
		for (int i = 0; i < 4; i++)
		{
			int n_x = cur_x + dir_x[i];
			int n_y = cur_y + dir_y[i];
			if (n_x >= N || n_y >= N || n_x < 0 || n_y < 0 || groupmap[n_x][n_y] != g2num)
				continue;
			else
			{
				nearnum += 1;
			}
		}

	}
	int score = (g1size + g2size) * num1 * num2 * nearnum;
	return score;
}
int getscore(vector<vector<int>> vec)
{
	vector<number> info[900];
	vector<vector<bool>> is_visited(N, vector<bool>(N, false));
	vector<vector<int>> groupmap(N, vector<int>(N, 0));
	int groupnum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_visited[i][j] == true)
				continue;
			doBFS(vec, info, is_visited, groupnum, i, j, groupmap);
			groupnum += 1;
		}

	} //그룹의 개수 그룹에 있는 점들의정보를 얻음

	int score = 0;
	for (int i = 0; i < groupnum - 1; i++)
	{

		for (int j = i + 1; j < groupnum; j++)
		{
			vector<number> g1 = info[i];
			vector<number> g2 = info[j];
			int cur_score = computescore(g1, g2, groupmap);
			score += cur_score;

		}
	}





	return score;




}
void rotate(vector<vector<int>>& vec)
{
	int midpoint_x = N / 2;
	int midpoint_y = N / 2;
	vector<vector<int>> temp(N, vector<int>(N, 0));
	//top left
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			temp[i][j] = vec[(N / 2) - j - 1][i];
		}
	}
	//bottom right
	for (int i = midpoint_x + 1; i < N; i++)
	{
		for (int j = midpoint_x + 1; j < N; j++)
		{
			temp[i][j] = vec[1.5 * N - j][i];
		}
	}
	//top right
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = midpoint_x + 1; j < N; j++)
		{
			temp[i][j] = vec[N - j - 1][midpoint_x + 1 + i];
		}
	}
	//bottomleft
	for (int i = midpoint_x + 1; i < N; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			temp[i][j] = vec[N - j - 1][i - midpoint_x - 1];
		}
	}
	//십자가

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//left side
			if (i == midpoint_x && j < midpoint_y)
			{
				temp[N - 1 - j][i] = vec[i][j];
			}
			//up side
			if (i < midpoint_x && j == midpoint_y)
			{
				temp[j][i] = vec[i][j];
			}
			//right side
			if (i == midpoint_x && j > midpoint_y)
			{
				temp[N - 1 - j][i] = vec[i][j];
			}

			//downside(
			if (i > midpoint_x && j == midpoint_y)
			{
				temp[j][i] = vec[i][j];

			}
			if (i == midpoint_x && j == midpoint_y)
			{
				temp[j][i] = vec[i][j];
			}
		}

	}

	vec = temp;
}
int main()
{

	cin >> N;
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
	int answer = 0;
	int firstscore = getscore(vec);
	rotate(vec);




	int secondscore = getscore(vec);
	rotate(vec);
	int thirdscore = getscore(vec);
	rotate(vec);
	int fourthscore = getscore(vec);
	answer = firstscore + secondscore + thirdscore + fourthscore;
	cout << answer;


}