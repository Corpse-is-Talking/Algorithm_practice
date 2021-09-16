#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Dice
{
public:
	int p1=0, p2=0, p3=0, p4=0, p5=0, p6=0;
	Dice()
	{
	}
	void swap(int command)
	{
		switch (command)
		{
		case 1:
		{
			int temp1,temp3, temp4, temp6 = 0;
			temp1 = p1;
			temp3 = p3;
			temp4 = p4;
			temp6 = p6;
			p3 = temp1;
			p1 = temp4;
			p6 = temp3;
			p4 = temp6;
			
		}
		break;
		case 2:
		{
			int temp1, temp3, temp4, temp6 = 0;
			temp1 = p1;
			temp3 = p3;
			temp4 = p4;
			temp6 = p6;
			p1 = temp3;
			p3 = temp6;
			p6 = temp4;
			p4 = temp1;
		}
		break;
		case 3:
		{
			int temp1, temp2, temp5, temp6 = 0;
			temp1 = p1;
			temp2 = p2;
			temp5 = p5;
			temp6 = p6;
			p1 = temp5;
			p2 = temp1;
			p5 = temp6;
			p6 = temp2;

		}
		break;
		case 4:
		{
			int temp1, temp2, temp5, temp6 = 0;
			temp1 = p1;
			temp2 = p2;
			temp5 = p5;
			temp6 = p6;
			p1 = temp2;
			p2 = temp6;
			p5 = temp1;
			p6 = temp5;
		}
		break;

		default:
			break;
		}
			

	}


};
int main()
{
	//input until command given
	int N = 0, M = 0, x = 0, y = 0, K=0;
	cin >> N >> M >> x >> y >> K;
	vector<vector<int>> mapnum(N,vector<int>(M,0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int	m_num=0;
			cin >> m_num;
			mapnum[i][j] = m_num;
		}
	}
	//command
	Dice dice;

	for (int i = 0; i < K; i++)
	{
		int command = 0;
		cin >> command;
		bool isOut = false;
		switch (command)
		{
		case 1:
			if (y + 1 > M- 1)
			{
				isOut = true;
				break;
			}
			else
			{
				
				y += 1;
				break;
			}

		case 2:
			if (y - 1 < 0)
			{
				isOut = true;
				break;
				
			}
			else
			{
				y -= 1;
				break;
			}
		case 4: 
			if (x + 1 > N- 1)
			{
				isOut = true;
				break;
			}
			else
			{
				x += 1;
				break;
			}


		case 3: 
			if (x - 1 < 0)
			{
				isOut = true;
				break;
			}
			else
			{
				x-=1;
				break;
			}
		default: 	
			break;
		}
		if (isOut)
		{
			continue;
		}
			
		else 
		{
			dice.swap(command);
			if (mapnum[x][y] == 0)
			{
				mapnum[x][y] = dice.p6;
			}
			else
			{
				dice.p6 = mapnum[x][y];
				mapnum[x][y] = 0;
			}
			if (i < K - 1) cout << dice.p1 << "\n";
			else cout << dice.p1;
		}
		

	}
	



}