#include <vector>
#include <iostream>
using namespace std;
int dir_x[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dir_y[9] = { 0,-1,-1,0,1,1,1,0,-1 };
struct Fish
{
	int x;
	int y;
	int dir;

};
int shark_x, shark_y;
vector<Fish> fishmap[5][5];
int smellmap[5][5];
int maxeating;
int sdx[5] = { 0,-1,0,1,0 };
int sdy[5] = { 0,0,-1,0,1 };
int sharkroute[4];
int temproute[4];
int routesimulation()
{
	bool visit[5][5] = { false, };
	int x = shark_x;
	int y = shark_y;
	int eat = 0;
	for (int i = 0; i < 3; i++)
	{
		int dir = temproute[i];
		int nx = x + sdx[dir];
		int ny = y + sdy[dir];
	}
}
void findroute(int cnt)
{
	if (cnt == 3)
	{
		int eatNum = routesimulation();
		if (eatNum > maxeating)
		{
			maxeating = eatNum;
			for (int i = 0; i < 3; i++)
			{
				sharkroute[i] = temproute[i];
			}
		}
		return;

	}
	for (int i = 0; i < 4; i++)
	{
		temproute[cnt] = i+1;
		findroute(cnt + 1);

	}

}
void copymap(vector<Fish> fmap[][5], vector<Fish>  copy_map[][5])
{
	for (int i = 1; i <=4; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			fmap[i][j] = copy_map[i][j];
		}

	}
}
int changedir(int dir)
{
	switch (dir)
	{
	case 1:
		return 8;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 7;


	}

}
void movefish()
{
	vector<Fish> tempMap[5][5];
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < fishmap[i][j].size(); k++)
			{
				int x = fishmap[i][j][k].x;
				int y = fishmap[i][j][k].y;
				int dir = fishmap[i][j][k].dir;
				int nx = x;
				int ny = y;
				int l = 0;
				bool isFound = false;
				for (int l = 0; l < 8; l++)
				{
					nx = x + dir_x[dir];
					ny = y + dir_y[dir];

					if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
					{
						if ((nx != shark_x || nx != shark_y) && (smellmap[nx][ny] == 0))
						{

							isFound = true;
							break;
						}
					}

				}
				dir = changedir(dir);
				if (isFound == true)
				{
					Fish f = { nx,ny,dir };
					tempMap[nx][ny].push_back(f);

				}
				else
				{
					Fish f = { x, y, dir };					
					tempMap[x][y].push_back(f);
					
				}

			}
			copymap(fishmap, tempMap); //물고기가 이동한 배열로 바꿔줌. 

		}
	}



}
int main()
{
	int M, S;
	cin >> M >> S;
	for (int i = 0; i < S; i++)
	{
		int temp_x, temp_y, temp_dir;
		cin >> temp_x >> temp_y >> temp_dir;
		Fish f = { temp_x,temp_y,temp_dir };
		fishmap[temp_x][temp_y].push_back(f);

	}
	
	cin >> shark_x >> shark_y;



}