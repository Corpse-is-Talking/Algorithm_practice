#include<iostream>
#include<vector>
using namespace std;
int N = 0;
int mat[5][5] = { 0, };
vector<vector<int>> origin(5,vector<int>(5,0));
vector<vector<int>> mul(vector<vector<int>>& vec1, vector<vector<int>>& vec2)
{
	vector<vector<int>> vec3(vec1.size(), vector<int>(vec1.size(), 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int m_num = 0;
			for (int k = 0; k < N; k++)
			{
				m_num += vec1[i][k] * vec2[k][j];

			}
			vec3[i][j] = m_num % 1000;
		}
	}
	return vec3;

}
void matmul( vector<vector<int>> vec1, vector<vector<int>> vec2,vector<vector<int>> &ans, long long  cur_1,long long  cur_2, long long  B)
{
	if (cur_1+cur_2 < B)
	{
		vector<vector<int>> vec3 = mul(vec1, vec2);
		matmul(vec3,vec3,ans,cur_1+cur_2,cur_1+cur_2, B);
	}
	else if (cur_1+cur_2 == B)
	{
		vector<vector<int>> vec3 = mul(vec1, vec2);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans[i][j] = vec3[i][j];
			}
		}
		return;
	}
	else
	{
		long long  n_B = B - cur_1;
		if (n_B == 1)
		{
			ans = mul(vec1, origin);
		}
		else if (n_B == 2)
		{
			vector<vector<int>> temp(N, vector<int>(N, 0));
			temp = mul(origin, origin);
			ans = mul(vec1, temp);
		}
		else
		{
			vector<vector<int>> temp(N, vector<int>(N, 0));
			matmul(origin, origin, temp, 1, 1, n_B);
			ans = mul(vec1, temp);
		}
	}

}
	

int main()
{
	long long int B = 0;
	cin >> N >> B;
	vector<vector<int>> vec1(N, vector<int>(N, 0));
	vector<vector<int>> ans(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input = 0;
			cin >> input;
			vec1[i][j] = input;
			origin[i][j] = input;
		}
	}
	if (B == 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << vec1[i][j]%1000 << " ";
			}
			cout << "\n";
		}

	}
	else
	{
		matmul(vec1,vec1,ans, 1,1, B);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << ans[i][j]<< " ";
			}
			cout << "\n";
		}
	}
	
}