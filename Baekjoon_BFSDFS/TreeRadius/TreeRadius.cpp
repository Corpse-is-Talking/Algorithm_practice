#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int getLen(int cur_node, vector<vector<int>>& tree, vector<int>& diameter)
{
    // a casual BFS
	vector<int> distance(diameter.size(), 0);
	distance[cur_node] = 0;
	queue<int> que;
	que.push(cur_node);
	int max_len = 0;
	while (!que.empty())
	{
		int cn = que.front();
		que.pop();
		for (int i = 0; i < tree[cn].size(); i++)
		{
			distance[tree[cn][i]] = distance[cn] + diameter[tree[cn][i]];
			que.push(tree[cn][i]);
			if (distance[tree[cn][i]] > max_len)
				max_len = distance[tree[cn][i]];
		}
	}
	return max_len;
}
int main()
{
	int n_node;
	cin >> n_node;
	vector<vector<int>> tree(n_node + 1);
	vector<int> diameter(n_node+1, 0);
	for (int i = 0; i < n_node-1; i++)
	{
		int p_node, c_node, distance;
		cin >> p_node >> c_node >> distance;
		tree[p_node].push_back(c_node);
		diameter[c_node] = distance;
	}
	int cur_max = 0;
    //for each node find the maximum length upon them
	for (int i = 1; i <= n_node; i++)
	{
		int cur_dis = 0;
		if (tree[i].size() == 0)
			cur_dis = 0;
		else if (tree[i].size() == 1)
			cur_dis = diameter[tree[i][0]]+getLen(tree[i][0], tree, diameter);
		else 
		{
			vector<int> maxdis;
            //for case when there are more than 2 children
			for (int j = 0; j < tree[i].size(); j++)
			{
				maxdis.push_back(diameter[tree[i][j]] + getLen(tree[i][j], tree, diameter));
			}
			sort(maxdis.begin(), maxdis.end(),greater<int>());
			cur_dis = maxdis[0] + maxdis[1];

		}
		
		
		if (cur_dis > cur_max)
			cur_max = cur_dis;
	}
	
	cout << cur_max ;
	return 0;
}