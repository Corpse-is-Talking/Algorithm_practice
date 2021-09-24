#include <iostream>
#include <vector>
using namespace std;
int N = 0;
int route = 0;
int col[15] = { 0, };
vector<vector<int>> info(15, vector<int>(15, 0));
bool isvisitable(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (col[i] == col[x] || abs(col[i] - col[x]) == x - i)
			return false;

	}
	return true;
}
void doDFS(int cur_x)
{

	if (cur_x==N)
	{
		route +=1;
		return;
	}

	//update non-visitable areax
	for (int i = 0; i < N; i++)
	{
		col[cur_x] = i;
		if(isvisitable(cur_x))
		{
			doDFS(cur_x + 1);
		}
	}

	//goto next row. and find available route.
	


}
int main()
{
	cin >> N;
	 // an N by N map construction.
	doDFS(0);
	cout << route;
	return 0;
}