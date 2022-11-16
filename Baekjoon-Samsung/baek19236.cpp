#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct fish
{
	int x, y, dir;
	bool alive;

};

int dir_x[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dir_y[] = { 0,0,-1,-1,-1,0,1,1 ,1 };

int cur_max = -1;

int changedir(int dir)
{
	switch(dir)
	{
	case 1:
		return 2;
	case 2:
		return 3;
	case 3:
		return 4;
	case 4:
		return 5;
	case 5:
		return 6;
	case 6:
		return 7;
	case 7:
		return 8;
	case 8:
		return 1;
	}

}
bool isfishmovable(int cur_x,int cur_y,int dir, vector<vector<int>> eatmap)
{
	int n_x = cur_x += dir_x[dir];
	int n_y = cur_y += dir_y[dir];
	if (n_x < 0 || n_x >= 4 || n_y < 0 || n_y >= 4)
		return false;
	if (eatmap[n_x][n_y]==-1)
		return false;
	return true;

}
void doDFS(int cnt,fish b, fish fish_info[],vector<vector<int>> eatmap)
{

	fish shark = b;

	cur_max = max(cur_max, cnt);
	fish temp[17];
	int t_eatmap[4][4];
	for (int i = 1; i < 17; i++)
	{
		temp[i] = fish_info[i];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			t_eatmap[i][j] = eatmap[i][j];

	}

	for (int l = 1; l <= 16; l++)
	{

		int cur_x = temp[l].x;
		int cur_y = temp[l].y;
		int dir = temp[l].dir;
		bool flag = false;
		if (temp[l].alive==false)
			continue;
		for (int i = 0; i < 8; i++)
		{
			if (isfishmovable(cur_x, cur_y, dir,eatmap) == true)
			{
				flag = true;
				break;
			}
			else
			{
				dir = changedir(dir);
			}

		}
		if (flag)
		{
			
			int n_x = cur_x + dir_x[dir];
			int n_y = cur_y + dir_y[dir];

			int idx = eatmap[n_x][n_y];
			int tp = eatmap[cur_x][cur_y];
			if (idx == 0)
			{
				temp[l].x = n_x;
				temp[l].y = n_y;
				temp[l].dir = dir;
				eatmap[cur_x][cur_y] = 0;
				eatmap[n_x][n_y] = tp;

			}
			
			else {
				eatmap[n_x][n_y] = l;
				temp[l].x = n_x;
				temp[l].y = n_y;
				temp[l].dir = dir;
				eatmap[cur_x][cur_y] = idx;
				temp[idx].x = cur_x;
				temp[idx].y = cur_y;
			}
		}



	}
	

	int cur_x = shark.x;
	int cur_y = shark.y;

	int n_x = cur_x;
	int n_y = cur_y;
	while (true)
	{

		//상어가 움직이는 경우의 수 생각.

		
		n_x += dir_x[shark.dir];
		n_y += dir_y[shark.dir];
		if (n_x >= 0 && n_x < 4 && n_y >= 0 && n_y < 4)
		{

			int idx = eatmap[n_x][n_y];
			if (idx == 0 )
				continue;
			eatmap[cur_x][cur_y] = 0;
			eatmap[n_x][n_y] = -1;
			shark = temp[idx];
			temp[idx].alive = false;
			doDFS(cnt + idx, shark, temp, eatmap);
			eatmap[cur_x][cur_y] = -1;
			eatmap[n_x][n_y] = idx;
			shark = b;
			temp[idx].alive = true;

		}
		else
			break;
	}
	

	return;

}
int main()
{
	fish fish_info[17];
	//int eatmap[4][4];
	vector<vector<int>>eatmap (4, vector<int>(4, 0)) ;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int cur_num, cur_dir;
			cin >> cur_num >> cur_dir;
			eatmap[i][j] = cur_num;
			fish_info[cur_num].x = i;
			fish_info[cur_num].y = j;
			fish_info[cur_num].dir = cur_dir;
			fish_info[cur_num].alive = true;
		}

	}

	

	fish_info[eatmap[0][0]].alive = false;
	fish b = fish_info[eatmap[0][0]];
	int idx = eatmap[0][0];
	eatmap[0][0] = -1;
	
	doDFS(idx, b,fish_info,eatmap);
	cout << cur_max;


}