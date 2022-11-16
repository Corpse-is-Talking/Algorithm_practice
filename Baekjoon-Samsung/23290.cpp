#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct FISH
{
	int x;
	int y;
	int dir;

};
int fish_map[11][11] = { 0, };
int fish_count[11][11] = { 0, };
int smell[11][11] = { 0, };

void movefish()
{
	for (int i = 1; i < 11; i++)
	{


	}

}
int main()
{
	int M, S;
	cin >> M >> S;
	for (int i = 0; i < S; i++)
	{
		int x, y, dir;
		cin >> x >> y >> dir;
		fish_map[x][y] = dir;
		fish_count[x][y] += 1;
	}
	int shark_x, shark_y;
	cin >> shark_x>> shark_y;
	for (int i = 0; i < S; i++)
	{
		movefish();
		copyfish();
		moveshark();



	}



	return 0;
}