#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec(10, vector<int>(10, 0));
int cur_min = 99999999;
bool ispaperokay(int size, int cur_x, int cur_y)
{
	bool isokay = true;
	for (int i = cur_x; i < cur_x + size; i++)
	{
		for (int j = cur_y; j < cur_y + size; j++)
		{
			if (i > 9 || j > 9|| i < 0 || j < 0||vec[i][j]==0)
				return false;
		}
	}
	return true;

}
void doDFS(int cur_x, int cur_y, int cnt, vector<int> papercount)
{
	int temp_x = cur_x; //1�� ��ǥ�� ã����
	int temp_y = cur_y; //1�� ��ǥ�� ã����..
	while (vec[temp_x][temp_y] == 0)//1�� ã�ƾߵ�!!!
	{
		temp_y++;
		if (temp_y >= 10)
		{
			temp_x++;
			if (temp_x >= 10)//�ǳ� ����!!
			{
				cur_min = min(cur_min, cnt);
				return;
			}
			temp_y = 0;
		}
	}
	if (cnt >= cur_min)
		return;

	for (int i = 4; i >=0 ; i--) // ��� ���̿� ���Ͽ� Ȯ��..
	{
		int cur_size = i + 1;
		if (papercount[i] > 0)
		{
			if (ispaperokay(cur_size, temp_x, temp_y))
			{
				for (int a = temp_x; a < temp_x + cur_size; a++)
				{
					for (int b = temp_y; b < temp_y + cur_size; b++)
					{
						vec[a][b] = 0;

					}
				}
				papercount[i] -= 1;
				doDFS(temp_x , temp_y , cnt + 1, papercount);
				for (int a = temp_x; a < temp_x + cur_size; a++)
				{
					for (int b = temp_y; b < temp_y + cur_size; b++)
					{
						vec[a][b] = 1;

					}
				}
				papercount[i] += 1;

			}

		}


	}



}
int main()
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int temp;
			cin >> temp;
			vec[i][j] = temp;
		}
	}
	vector<int> papercount = { 5,5,5,5,5 };
	int cnt = 0;
	doDFS(0, 0, cnt,papercount);

	if (cur_min == 99999999)
		cout << -1;
	else
		cout << cur_min;






}