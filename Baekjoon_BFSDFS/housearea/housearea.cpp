#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int space[26][26] = { -1, };
bool is_visited[26][26] = { false, };
int BFS(int x, int y,int n)
{
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));
	int count = 1;
	while (!que.empty())
	{
		int x_temp = que.front().first;
		int y_temp = que.front().second;
		

		int x_left = x_temp - 1;
		int y_down = y_temp - 1;
		int x_right = x_temp + 1;
		int y_up = y_temp + 1;
		que.pop();
		if (x_left >= 0 && is_visited[x_left][y_temp] == false && space[x_left][y_temp] == 1)
		{
			is_visited[x_left][y_temp] = true;
			que.push(make_pair(x_left, y_temp));
			count++;
		}//left of the current space..
		if (x_right <= n && is_visited[x_right][y_temp] == false && space[x_right][y_temp] == 1)
		{
			is_visited[x_right][y_temp] = true;
			que.push(make_pair(x_right, y_temp));
			count++;
		}//right side 
		if (y_down >= 0 && is_visited[x_temp][y_down] == false && space[x_temp][y_down] == 1)
		{
			is_visited[x_temp][y_down] = true;
			que.push(make_pair(x_temp, y_down));
			count++;
		}// down..
		if (y_up <= n && is_visited[x_temp][y_up] == false && space[x_temp][y_up] == 1)
		{
			is_visited[x_temp][y_up] = true;
			que.push(make_pair(x_temp, y_up));
			count++;
		}//left of the current space..

	}
	return count;


}
int main()
{

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string data = " ";
		cin >> data;
		for (int j = 0; j < data.size(); j++)
		{
			int to_put = data[j]-'0';

			space[i][j] = to_put;
		}
	}
	int count = 0;
	int housenum = 0;
	vector<int> info;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (space[i][j]==1 && is_visited[i][j] == false)
			{
				is_visited[i][j] = true;
				count=BFS(i, j,n-1);
				housenum++;
				info.push_back(count);
			}

		}
	}
	sort(info.begin(), info.end());
	cout << housenum << "\n";
	for (int i = 0; i < info.size(); i++)
	{
		cout << info[i] << "\n";
	}
	

}