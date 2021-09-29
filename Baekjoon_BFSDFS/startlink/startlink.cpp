#include<iostream>
#include<vector>
using namespace std;
int last = 0, des = 0, UP = 0, DOWN = 0;
int mmove = 0;
bool isava = true;
bool isvisited[1000001] = { false };

void elevator(int curstate)
{
	if (curstate == des)
		return;
	
	if (isvisited[curstate] == true)
	{
		isava = false;
		return;
	}

	isvisited[curstate] = true;

	if (curstate + UP > last && curstate - DOWN < 1)
	{
		isava = false;
		return;
	}


	if (curstate + UP > last)
	{
		mmove++;
		elevator(curstate - DOWN);
		return;
	}
	if (curstate - DOWN < 1)
	{
		mmove++;
		elevator(curstate + UP);
		return;

	}
	if (curstate + UP > des)
	{
		mmove++;
		elevator(curstate - DOWN);
		return;
	}
	if (curstate - DOWN < des)
	{
		mmove++;
		elevator(curstate + UP);
		return;
	}

	if (curstate-DOWN >= des)
	{
		mmove++;
		elevator(curstate - DOWN);
		return;
	}
	if (curstate+UP <= des)
	{
		mmove++;
		elevator(curstate + UP);
		return;
	}


}
int main()
{
	int cur = 0;
	cin >> last >> cur >> des >> UP >> DOWN;
	elevator(cur);
	if (isava==false) cout << "use the stairs" << endl;
	else cout << mmove;

}