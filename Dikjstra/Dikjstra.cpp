	#include<iostream>
	#include<queue> //put it in the que for visited ones.
	#include<vector>
	#include<unordered_map> // to save the information of distances from the starting node
	using namespace std;
	void getData( vector<vector<pair<int, int>>> &v, int e_num)
	{
		//given data of Node, Node, weight...
		for (int i = 0; i < e_num; i++)
		{
			int temp1 = 0, temp2, temp3; // i.e temp3 is the weight of passing through node temp1 and node temp2 
			cin >> temp1 >> temp2 >> temp3; //
			v[temp1].push_back(make_pair(temp2,temp3));  // form each element in v , v[temp1] refers to th
		}

	}
	int main()
	{
		int v_num = 0, e_num = 0;
		cin >> v_num >> e_num;
		int start_num = 0;
		cin >> start_num;
		vector<vector<pair<int, int>>> v(v_num + 1); // initializing technique, as there are total n vertices(1~n), initalizea as v_num+1
		vector<int> distance(v_num + 1,1000000); //1000000 for infinity..
		getData(v, e_num);
		distance[start_num] = 0;
		priority_queue<pair<int,int>> que;
		que.push({ distance[start_num] ,start_num});
		while (!que.empty())
		{
			int cur_cost = -que.top().first;
			int cur_point = que.top().second;
			que.pop();
			if (distance[cur_point] < cur_cost)
				continue;
			for (int i = 0; i < v[cur_point].size(); i++)
			{
				if (distance[v[cur_point][i].first] >cur_cost + v[cur_point][i].second)
				{
					distance[v[cur_point][i].first]=cur_cost + v[cur_point][i].second; //relax if updated..
					que.push(make_pair( -distance[v[cur_point][i].first], v[cur_point][i].first));
				}
			}
		}
		for (int i = 1; i <= v_num; i++)
		{
			if (distance[i] == 1000000)
				cout << "INF\n" ;
			else
				cout << distance[i] << '\n';
		}
	}