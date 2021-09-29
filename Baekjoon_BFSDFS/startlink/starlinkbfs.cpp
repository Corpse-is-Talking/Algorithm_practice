#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int last = 0, des = 0, UP = 0, DOWN = 0;
int mmove = 0;
bool isava = true;
bool isvisited[1000001] = { false };
void doBFS(int current)
{
	queue<pair<int, int>> que;
	que.push(make_pair(current, 0));
	int dx[2] = { 0,};
	dx[0] = UP;
	dx[1] = -DOWN;
	isvisited[current] = true;
	bool isfound = false;
	while (!que.empty())
	{
		int cur_state = que.front().first;
		int mcount = que.front().second;
		if (cur_state == des)
		{
			isfound = true;
			cout << mcount;
			return;
		}
		que.pop();
		
		for (int i = 0; i < 2; i++)
		{
			int nx = cur_state + dx[i];
			if (nx<=0 || nx>last)
				continue;
			if (isvisited[nx] == false)
			{
				isvisited[nx] = true;
				que.push(make_pair(nx, mcount + 1));
			}
		}

	}
	if (!isfound) cout << "use the stairs";
}
int main()
{
	int cur = 0;
	cin >> last >> cur >> des >> UP >> DOWN;
	doBFS(cur);

}