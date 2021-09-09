#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n_node;
	cin >> n_node;
	vector<int> parents(n_node+1,0); //to show the parents, check if a certain node has a parents
	vector<vector<int>> link(n_node+1);//a to store the info of vertices
	parents[1] = 1;
	//input handling save in link
	for (int i = 0; i < n_node-1; i++)
	{
		int first;
		int second;
		cin >> first >> second;
		link[first].push_back(second);
		link[second].push_back(first);

	}
	//for bfs..
	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int cur_check = que.front();
		que.pop();
		for(int i=0; i<link[cur_check].size(); i++)
		{
			//if the child already has a parents then no need to push..
			int child = link[cur_check][i];
			if (parents[child] == 0)
			{
				parents[child] = cur_check;
				que.push(child);
			}
		}

	}


	for (int i = 2; i <= n_node; i++)
	{
		if (i != n_node)
			cout << parents[i] << '\n'; //\n for speed.
		else
			cout << parents[i];

	}




}