#include <vector>
#include <iostream>
#include<queue>
#include<string>
using namespace std;
int t_map[4][8] = { 0, };

void rotate(int num, int t_dir)
{
	int t_num = num - 1;
	int temp=0;
	if (t_dir == 1)
	{
		temp = t_map[t_num][7];
		for (int i = 6; i >=0; i--)
		{
			t_map[t_num][i + 1] = t_map[t_num][i];

		}
		t_map[t_num][0] = temp;

		

	}
	if (t_dir == -1)
	{
		temp = t_map[t_num][0];
		for (int i = 0; i < 7; i++)
		{
			t_map[t_num][i ] = t_map[t_num][i+1];

		}
		t_map[t_num][7] = temp;

	}


}
void checkrotate(int t_num, int t_dir)
{
	if (t_num == 1)
	{
		if (t_map[0][2] == t_map[1][6])
		{
			rotate(1, t_dir);
		}
		else
		{
			if (t_map[1][2] == t_map[2][6])
			{
				rotate(1, t_dir);
				rotate(2, t_dir * -1);
			}
			else
			{
				if (t_map[2][2] == t_map[3][6])
				{
					rotate(1, t_dir);
					rotate(2, t_dir * -1);
					rotate(3, t_dir);
				}
				else
				{
					rotate(1, t_dir);
					rotate(2, t_dir * -1);
					rotate(3, t_dir);
					rotate(4, t_dir * -1);

				}
			}
		}
	}
	if (t_num == 2)
	{
		if (t_map[0][2] != t_map[1][6])
		{
			rotate(1, t_dir * -1);
		}
		if (t_map[1][2] == t_map[2][6])
		{
			rotate(2, t_dir);
		}
		else
		{
			if (t_map[2][2] == t_map[3][6])
			{
				rotate(2, t_dir);
				rotate(3, t_dir * -1);
			}
			else
			{
				rotate(2, t_dir);
				rotate(3, t_dir * -1);
				rotate(4, t_dir);
			}
		}

	}
	if (t_num == 3)
	{
		if (t_map[2][2] != t_map[3][6])
		{
			rotate(4, t_dir * -1);
		}
		if (t_map[1][2] == t_map[2][6])
		{
			rotate(3, t_dir);
		}
		else
		{
			if (t_map[0][2] == t_map[1][6])
			{
				rotate(3, t_dir);
				rotate(2, t_dir * -1);
			}
			else
			{
				rotate(3, t_dir);
				rotate(2, t_dir * -1);
				rotate(1, t_dir);
			}
		}

	}
	if (t_num == 4)
	{
		if (t_map[2][2] == t_map[3][6])
		{
			rotate(4, t_dir);
		}
		else
		{
			if (t_map[1][2] == t_map[2][6])
			{
				rotate(4, t_dir);
				rotate(3, t_dir * -1);
			}
			else
			{
				if (t_map[0][2] == t_map[1][6])
				{
					rotate(4, t_dir);
					rotate(3, t_dir * -1);
					rotate(2, t_dir);
				}
				else
				{
					rotate(4, t_dir);
					rotate(3, t_dir * -1);
					rotate(2, t_dir);
					rotate(1, t_dir * -1);

				}
			}
		}

	}
}
int main()
{
	string str;
	for (int i = 0; i < 4; i++)
	{

		cin >> str;
		for (int j = 0; j < 8; j++)
		{
			t_map[i][j] = str[j] - '0';
		}

	}
	int r_num = 0;
	cin >> r_num;
	for (int i = 0; i < r_num; i++)
	{
		int t_num, t_dir;
		cin >> t_num >> t_dir;
		//logic..
		checkrotate(t_num, t_dir);

	}
	int score = 0;
	if (t_map[0][0] == 1)
		score += 1;
	if (t_map[1][0] == 1)
		score += 2;
	if (t_map[2][0] == 1)
		score += 4;
	if (t_map[3][0] == 1)
		score += 8;

	cout << score;

	return 0;
}