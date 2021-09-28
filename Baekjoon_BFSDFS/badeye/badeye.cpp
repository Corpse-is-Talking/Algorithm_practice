#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N = 0;
char info[100][100] = { 0, };
bool is_visited[100][100] = { false, };
int counts = 0;
int b_counts = 0;
void DFS(int i, int j, char letter)
{
	if (i >= N || j >= N || i < 0 || j < 0 || is_visited[i][j] == true||info[i][j]!=letter)
		return;
	is_visited[i][j] = true;
	DFS(i + 1, j,letter);
	DFS(i - 1, j,letter);
	DFS(i, j + 1,letter);
	DFS(i, j - 1,letter);

}
void badeyeDFS(int i, int j, char letter)
{
	if (i >= N || j >= N || i < 0 || j < 0 || is_visited[i][j] == false)
		return;
	if ((letter == 'R' || letter == 'G') && (info[i][j] == 'R' || info[i][j] == 'G'))
	{
		is_visited[i][j] = false;
		badeyeDFS(i + 1, j, letter);
		badeyeDFS(i - 1, j, letter);
		badeyeDFS(i, j + 1, letter);
		badeyeDFS(i, j - 1, letter);
	}
	else if (letter == info[i][j])
	{
		is_visited[i][j] = false;
		badeyeDFS(i + 1, j, letter);
		badeyeDFS(i - 1, j, letter);
		badeyeDFS(i, j + 1, letter);
		badeyeDFS(i, j - 1, letter);
	}
	else
		return;

}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			info[i][j] = input[j];

		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_visited[i][j] == false)
			{
				counts++;
				DFS(i, j, info[i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_visited[i][j] == true)
			{
				b_counts++;
				badeyeDFS(i, j, info[i][j]);
			}
		}
	}
	cout << counts << " " << b_counts;
	
}

