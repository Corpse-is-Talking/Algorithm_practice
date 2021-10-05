#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N = 0;
int a[11] = { 0, };
int plus_num = 0, minus_num = 0, mul_num = 0, div_num = 0;
int cur_min = 1000000001;
int cur_max = -1000000001;
void DFS(int plus, int minus, int mul, int div,int logic,int seq,int cur)
{
	if (plus > plus_num || minus > minus_num || mul > mul_num || div > div_num)
		return;
	int cur_sum = 0;
	if (seq == 0)
		cur_sum = a[0];
	else
	{
		if (logic == 1)
			cur_sum = cur + a[seq];
		else if (logic == 2)
			cur_sum = cur - a[seq ];
		else if (logic == 3)
			cur_sum = cur * a[seq];
		else if (logic == 4)
			cur_sum = cur / a[seq ];

	}

	if (seq == N-1 )
	{
		if (cur_max < cur_sum)
			cur_max = cur_sum;
		if (cur_min > cur_sum)
			cur_min = cur_sum;
		//caculate.
		return;
	}
	DFS(plus + 1, minus, mul, div,1,seq+1,cur_sum);
	DFS(plus , minus+1, mul, div,2,seq+1,cur_sum);
	DFS(plus , minus, mul+1, div,3,seq+1,cur_sum);
	DFS(plus , minus, mul, div+1,4,seq+1,cur_sum);


}
int main()
{
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		a[i] = input;
	}
	
	cin >> plus_num>>minus_num>>mul_num>>div_num;
	DFS(0, 0, 0, 0,0,0,0);
	cout << cur_max << endl;
	cout << cur_min << endl;

}