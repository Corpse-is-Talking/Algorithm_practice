	#include<iostream>
	#include<queue> //put it in the que for visited ones.
	#include<vector>
	#include<unordered_map> // to save the information of distances from the starting node
	using namespace std;
	/*
	Data given: first line : number of vertices,and edges
				second line: starting point(which will be starting from 1)
				rest of the line: Node Node Cost information (i.e 3 2 1 means it costs 1 to go from 3 to 2)

	*/
	int main(void)
	{
		int v_num=0, e_num=0, start_node=0; //initialization before calculation
		cin >> v_num>>e_num >> start_node; //get input
		vector<vector<pair<int,int>>> vec(v_num+1); // create vector of each node holding information of distance to other node
		vector<int>distance(v_num+1,1000000); //initialized as infinity (or a big number)
		// get data
		for(int i=0; i<e_num; i++)
		{
			int d1=0,d2=0,d3=0;
			cin>>d1>>d2>>d3;
			vec[d1].push_back(make_pair(d2,d3)); //vec[d1] holds information of distance d3 between node d2
		}
		distance[start_node]=0;
		priority_queue<pair<int,int>> que;
		que.push(make_pair(distance[start_node],start_node));
		while(!que.empty())
		{
			int cur_dis=-que.top().first; //will be distance minus because its max heap but we want the  min dis
			int cur_node= que.top().second; //will get the current node 
			que.pop();
			for(int i=0; i<vec[cur_node].size(); i++)
			{
				int node=vec[cur_node][i].first;
				int dis=vec[cur_node][i].second;
				if(distance[node]<=distance[cur_node]+dis)
					continue;
				else
				{
					distance[node]=distance[cur_node]+dis; //update if distance can be reduced via other route.

				}
				que.push(make_pair( -distance[node],node)); //push the updated note to the que.
	
			}
			
		}
		for (int i = 1; i <= v_num; i++)
		{
			if (distance[i] == 1000000)
				cout << "INF\n" ;
			else
				cout << distance[i] << '\n';
		}
		return 0;
	}