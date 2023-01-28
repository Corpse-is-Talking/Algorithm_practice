#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int chickenmap[50][50] = { 0 };
vector<vector<int>> comb;
int getdis(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
int getmindis(vector<pair<int, int>> chicken, vector<pair<int, int >> house, vector<int> vec)
{
	int totaldis = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int housedis = 9999999;
		for (int j = 0; j < vec.size(); j++)
		{
			int curdis=getdis(house[i].first, house[i].second, chicken[vec[j]-1].first, chicken[vec[j]-1].second);
			if (curdis < housedis)
				housedis = curdis;
		}
		totaldis += housedis;
	}
	return totaldis;
}

void doCombination(int depth, int curnum, int arr_size, vector<int> vec)
{
	if (depth== M)
	{
		comb.push_back(vec);
		return;
	}
	for (int i = curnum; i <= arr_size; i++)
	{
		vec[depth] = i;
		doCombination(depth + 1, i+1,arr_size, vec);
	}
}
int main()
{
	cin >> N >> M;
	vector<pair<int, int>> chicken;
	vector<pair<int, int >> house;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				house.push_back(make_pair(i, j));
				
			}
			if (temp == 2)
			{
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> vec(M, 0);
	doCombination(0,1,  chicken.size(), vec);
	int min_dis = 9999999999;
	for (auto& e : comb)
	{	

		int cur_dis=getmindis(chicken, house, e);
		if (min_dis > cur_dis)
			min_dis = cur_dis;
	}
	cout << min_dis;

}