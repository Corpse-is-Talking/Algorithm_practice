#include <vector>
#include <iostream>
using namespace std;
int dir_y[] = { -1,0,1,0 };
int dir_x[] = { 0,1,0,-1 };
int sand_out = 0;
int changedir(int dir)
{
	if (dir == 0)
		return 1;
	if (dir == 1)
		return 2;
	if (dir == 2)
		return 3;
	if (dir == 3)
		return 0;


}
bool checkout(int N, int cur_x, int cur_y)
{
	if (cur_x >= N || cur_x < 0 || cur_y >= N || cur_y < 0)
		return true;
	return false;

}
void movesand(vector<vector<int>>& vec, int cur_x, int cur_y, int N,int dir, int tornadolength)
{
	int temp_x = cur_x;
	int temp_y = cur_y;
	while (tornadolength >= 1)
	{
		temp_x += dir_x[dir];
		temp_y += dir_y[dir];
		
		int sandtomove = vec[temp_x][temp_y];
		vec[temp_x][temp_y] = 0;
		int tenpct = sandtomove *10/100;
		int sevenpct = sandtomove * 7/100;
		int onepct = sandtomove /100;
		int twopct = sandtomove /50;
		int fivepct = sandtomove /20;
		int alpha = sandtomove-(2*(onepct+sevenpct+tenpct+twopct)+fivepct);

		// 온방향이랑 같은방향
		int alpha_x = temp_x + dir_x[dir];
		int alpha_y = temp_y + dir_y[dir];
		if (checkout(N, alpha_x, alpha_y))
		{
			sand_out += alpha;

		}
		else
		{
			vec[alpha_x][alpha_y] += alpha;
		}
		int five_x = temp_x + 2*dir_x[dir];
		int five_y = temp_y + 2*dir_y[dir];
		if (checkout(N, five_x, five_y))
		{
			sand_out += fivepct;

		}
		else
		{
			vec[five_x][five_y] += fivepct;
		}
		


		int backdir = (dir + 2) % 4;
		int leftdir = (dir + 1) % 4;
		int rightdir = (dir + 3) % 4;

		//대각 위아래 왼오른

		int one_x_1 = temp_x + dir_x[backdir]+dir_x[rightdir];
		int one_y_1 = temp_y + dir_y[backdir]+dir_y[rightdir];
		if (checkout(N, one_x_1, one_y_1))
		{
			sand_out += onepct;

		}
		else
		{
			vec[one_x_1][one_y_1] += onepct;
		}


		int ten_x_1 = temp_x + dir_x[dir]+dir_x[rightdir];
		int ten_y_1 = temp_y + dir_y[dir]+dir_y[rightdir];
		if (checkout(N, ten_x_1, ten_y_1))
		{
			sand_out += tenpct;

		}
		else
		{
			vec[ten_x_1][ten_y_1] += tenpct;
		}


		int one_x_2 = temp_x + dir_x[backdir] + dir_x[leftdir];
		int one_y_2 = temp_y + dir_y[backdir] + dir_y[leftdir];
		if (checkout(N, one_x_2, one_y_2))
		{
			sand_out += onepct;

		}
		else
		{
			vec[one_x_2][one_y_2] += onepct;
		}
		int ten_x_2= temp_x + dir_x[dir] + dir_x[leftdir];
		int ten_y_2 = temp_y + dir_y[dir] + dir_y[leftdir];
		if (checkout(N, ten_x_2, ten_y_2))
		{
			sand_out += tenpct;

		}
		else
		{
			vec[ten_x_2][ten_y_2] += tenpct;
		}

		
		int two_x_1 = temp_x + 2*dir_x[rightdir];
		int two_y_1 = temp_y + 2*dir_y[rightdir];
		if (checkout(N, two_x_1, two_y_1))
		{
			sand_out += twopct;

		}
		else
		{
			vec[two_x_1][two_y_1] += twopct;
		}


		int two_x_2 = temp_x + 2 * dir_x[leftdir];
		int two_y_2 = temp_y + 2 * dir_y[leftdir];
		if (checkout(N, two_x_2, two_y_2))
		{
			sand_out += twopct;

		}
		else
		{
			vec[two_x_2][two_y_2] += twopct;
		}


		int seven_x_1 = temp_x +  dir_x[rightdir];
		int seven_y_1 = temp_y + dir_y[rightdir];
		if (checkout(N, seven_x_1, seven_y_1))
		{
			sand_out += sevenpct;

		}
		else
		{
			vec[seven_x_1][seven_y_1] += sevenpct;
		}


		int seven_x_2 = temp_x +  dir_x[leftdir];
		int seven_y_2 = temp_y +  dir_y[leftdir];
		if (checkout(N, seven_x_2, seven_y_2))
		{
			sand_out += sevenpct;

		}
		else
		{
			vec[seven_x_2][seven_y_2] += sevenpct;
		}





		tornadolength--;
	}

}
void movetornado(vector<vector<int>>& vec, int N, int cur_x, int cur_y)
{
	int tornadolength = 1;
	int dir = 0;
	while (tornadolength <= N-1)
	{

		movesand(vec, cur_x, cur_y, N, dir, tornadolength);
		cur_x += dir_x[dir] * tornadolength;
		cur_y += dir_y[dir] * tornadolength;
		dir = changedir(dir);

		movesand(vec, cur_x, cur_y, N, dir, tornadolength);
		cur_x += dir_x[dir] * tornadolength;
		cur_y += dir_y[dir] * tornadolength;
		dir = changedir(dir);
		tornadolength += 1;

	}
	tornadolength -= 1;
	movesand(vec, cur_x, cur_y, N, dir, tornadolength);
	cur_x += dir_x[dir] * tornadolength;
	cur_y += dir_y[dir] * tornadolength;

}
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> vec(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			vec[i][j] = temp;

		}


	}
	int midpoint_x = N / 2;
	int midpoint_y = N / 2;
	movetornado(vec, N, midpoint_x, midpoint_y);
	cout << sand_out;






}