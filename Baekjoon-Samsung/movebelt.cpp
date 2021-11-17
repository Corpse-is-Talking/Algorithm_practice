#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int N=0,K = 0;
int capa[1001] = { 0, };
bool is_robot[1001] = { false, };
bool is_checked[1001] = { false };
int main()
{
	cin >> N;
	cin >> K;
	for (int i = 1; i <= 2 * N; i++)
	{
		int input = 0;
		cin >> input;
		capa[i] = input;

	}
	int start = 1;
	int end = N;
	queue<int> robot;
	int count = 0;
	while (K > 0)
	{
		//moving the belt
		if (start == 1)
		{
			start = 2 * N;
			end = end - 1;
		}
		else if (end == 1)
		{
			end = 2 * N;
			start = start - 1;

		}
		else
		{
			start = start - 1;
			end = end -1;
		}


		//check if robot exists-> first come first served-> queue

		if (!robot.empty())
		{
			int robot_num = robot.size();
			for (int i = 0; i < robot_num; i++)
			{
				int cur_index = robot.front();
				//check if movable
				robot.pop();
				if (cur_index == end)
				{
					is_robot[end] = false;
					continue;
				}

				if (cur_index == 2 * N)
				{
					if (is_robot[1] == true || capa[1] <= 0)
					{
						robot.push(2 * N);
						continue;
					}
						
					else
					{
						is_robot[cur_index] = false;
						is_robot[1] = true;
						capa[1] -= 1;

						if (end != 1)
							robot.push(1);
						else
							is_robot[end] = false;
					}
				
				}
				else
				{
					if (is_robot[cur_index + 1] == true || capa[cur_index + 1] <= 0)
					{
						robot.push(cur_index);
						continue;

					}
					else
					{
						is_robot[cur_index] = false;
						is_robot[cur_index+1] = true;
						capa[cur_index+1] -= 1;
					
					if(end!=cur_index+1)
						robot.push(cur_index+1);
					else
						is_robot[cur_index + 1] = false;
					}

				}
			}
		}
		if (capa[start] > 0 && is_robot[start] == false)
			robot.push(start);
		capa[start] -= 1;
		is_robot[start] = true;
		// check for the K num
		for (int i = 1; i <= 2 * N; i++)
		{
			if (capa[i] == 0 && is_checked[i] == false)
			{
				K--;
				is_checked[i] = true;
			}
		}




		count++;


	}
	cout << count;
	return 0;
}


