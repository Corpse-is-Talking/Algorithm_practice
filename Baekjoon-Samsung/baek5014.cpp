#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int F = 0, S = 0, G = 0, U = 0, D = 0;
int min_count = INT16_MAX;
int is_visited[1000001] = { 0 };

void elevator(int cur_state,int cur_count)
{

	if (cur_state < 1)
		return;
	if (cur_state > F)
		return;
	if (is_visited[cur_state] == true)
		return;
	if (cur_count > min_count)
		return;
	if (cur_state == G)
	{
		if (cur_count < min_count)
			min_count = cur_count;
		return;
	}
	is_visited[cur_state] = true;
	elevator(cur_state + U, cur_count + 1);
	elevator(cur_state - D, cur_count + 1);



}

int main()
{
	
	cin >> F >> S >> G >> U >> D;
	queue<int> que;
	for (int i = 0; i < 1000001; i++)
	{
		is_visited[i] = -1;
	}
	que.push(S);
	is_visited[S] = 0;
	while (!que.empty())
	{
		int cur_state = que.front();
		que.pop();
		if (cur_state + U <= F && is_visited[cur_state + U] == -1)
		{
			is_visited[cur_state + U] = is_visited[cur_state] + 1;
			que.push(cur_state + U);
		}
		if (cur_state - D >= 1 && is_visited[cur_state - D] == -1)
		{
			is_visited[cur_state -D] = is_visited[cur_state] + 1;
			que.push(cur_state -D);

		}



	}




	if (is_visited[G] == -1)
		cout << "use the stairs";
	else
	{
		cout << is_visited[G];
	}









}