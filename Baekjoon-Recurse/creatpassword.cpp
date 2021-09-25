#include<iostream>
#include<vector>
#include<algorithm>
int L = 0, C = 0;
using namespace std;
void printseq(vector<char> &ch, vector<char> &mem, int index, int count)
{
	if (C - index-1 < L - count)
		return;
	if (count == L)
	{
		mem[count - 1] = ch[index];
		bool found = false;
		int countz = 0;
		for (int i = 0; i < count; i++)
		{
			
			if (mem[i] == 'a' || mem[i] == 'e' || mem[i] == 'i' || mem[i] == 'o' || mem[i] == 'u')
			{
				found = true;
			}
			else
			{
				countz++;
			}
		}
		if (!found)
			return;
		if (countz < 2)
			return;
		for (int i = 0; i < count; i++)
			cout << mem[i];
		cout << "\n";
		return;
	}
	mem[count - 1] = ch[index];
	for (int j = index + 1; j < C; j++)
	{
		
		printseq(ch, mem,j, count + 1);
	}
	


}
int main()
{

	cin >> L >> C;
	vector<char> ch(C, 0);
	for (int i = 0; i < C; i++)
	{
		char input;
		cin >> input;
		ch[i] = input;
	}
	sort(ch.begin(), ch.end());
	vector<char> vec(4, 0);
	for (int i = 0; i < C; i++)
	{

		printseq(ch,vec,i, 1);

	}

}