#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//problem description...
//: A computer gets virus and virus moves to the very next(neighborhood) of certain node, find  out the number 
//of nodes infected by the starting node..


int main()
{
	//input data: starting node(1fixed), number of vertices, and edge information from node to node..
	int n_node = 0;
	int n_ver = 0;
	cin >> n_node >> n_ver;
	vector<vector<bool>> edge(n_node+1, vector<bool>(n_node+1, false));
	for (int i = 0; i < n_ver; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;
		edge[start][end] = true;
		edge[end][start] = true;
	}
	vector<bool> is_passed(n_node+1, false);
	is_passed[1] = true;
	
	queue<int> que;
	que.push(1);
	int count = 0;
	while (!que.empty())
	{
		int cur_node = que.front();
		que.pop();
		for (int i = 1; i <= n_node; i++)
		{
			if (edge[cur_node][i] && !is_passed[i] &&(i!=cur_node))
			{
				que.push(i);
				is_passed[i] = true;
				count++;
			}

		}
		
	}
	cout << count << endl;


	return 0;
}