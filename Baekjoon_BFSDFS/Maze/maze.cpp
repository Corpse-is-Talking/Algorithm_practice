/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include<string>
#include<queue>


using namespace std;
int map_info[101][101];
bool is_visited[101][101] = { false, };
int map_dis[101][101] = { 0, };
void doBFS(int start_x, int start_y, int N, int M)
{
    queue<pair<int, int>> que;
    que.push(make_pair(start_x, start_y));
    is_visited[start_x][start_y] = true;
    map_dis[start_x][start_y] = 1;
    while (!que.empty())
    {
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        que.pop();
        if (cur_x + 1 <= N && is_visited[cur_x + 1][cur_y] == false && map_info[cur_x + 1][cur_y] == 1)
        {
            is_visited[cur_x + 1][cur_y] = true;
            map_dis[cur_x + 1][cur_y] = map_dis[cur_x][cur_y] + 1;
            que.push(make_pair(cur_x + 1, cur_y));
        }//one down.
        if (cur_x - 1 > 0 && is_visited[cur_x - 1][cur_y] == false && map_info[cur_x - 1][cur_y] == 1)
        {
            is_visited[cur_x - 1][cur_y] = true;
            map_dis[cur_x - 1][cur_y] = map_dis[cur_x][cur_y] + 1;
            que.push(make_pair(cur_x - 1, cur_y));
        }//one up
        if (cur_y + 1 <= M && is_visited[cur_x][cur_y + 1] == false && map_info[cur_x][cur_y + 1] == 1)
        {
            is_visited[cur_x][cur_y + 1] = true;
            map_dis[cur_x][cur_y + 1] = map_dis[cur_x][cur_y] + 1;
            que.push(make_pair(cur_x, cur_y + 1));
        }//one right;
        if (cur_y - 1 > 0 && is_visited[cur_x][cur_y - 1] == false && map_info[cur_x][cur_y - 1] == 1)
        {
            is_visited[cur_x][cur_y - 1] = true;
            map_dis[cur_x][cur_y - 1] = map_dis[cur_x][cur_y] + 1;
            que.push(make_pair(cur_x, cur_y - 1));
        }//one down.

    }

}
int main()
{
    int N = 0, M = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string input;
        cin >> input;
        for (int j = 1; j <= M; j++)
        {
            int cur_num = input[j - 1] - '0';
            map_info[i][j] = cur_num;
        }

    }



    doBFS(1, 1, N, M);
    cout << map_dis[N][M];
    return 0;
}
