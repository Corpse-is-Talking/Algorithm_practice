#include<iostream>
using namespace std;
int N = 0;
int map_info[17][17];
int t_count = 0;
void doDFS(int x1, int y1, int x2, int y2)
{


	if (x1 > N || x2 > N || y1 > N || y2 > N || x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1)
		return;
	if (map_info[x1][y1] == 1 || map_info[x2][y2] == 1)
		return;
	if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1)
	{
		if (map_info[x2][y2 - 1]==1 || map_info[x2 - 1][y2]==1)
			return;
	}
	if ((x2 == N && y2 == N) || (x1 == N && y1 == N))
		t_count++;

	if (x1-x2==0)
	{
		//가로
		doDFS(x1, y1 + 1, x2, y2 + 1);
		doDFS(x1, y1 + 1, x2 + 1, y2 + 1);

	}
	else if (y1-y2==0)
	{
		//세로
		doDFS(x1 + 1, y1, x2 + 1, y2);
		doDFS(x1 + 1, y1, x2 + 1, y2 + 1);
	}
	else
	{
        //대각선.
		doDFS(x1 + 1, y1 + 1, x2, y2 + 1);
		doDFS(x1 + 1, y1 + 1, x2 + 1, y2);
		doDFS(x1 + 1, y1 + 1, x2 + 1, y2 + 1);

	}

}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;
			map_info[i][j] = input;
		}
	}
	doDFS(1, 1, 1, 2);
	cout << t_count;




}