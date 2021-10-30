#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N = 0;
vector<bool> parenthesis(20, false);
int cur_max = -999999;
int simplecal(int a, char arith, int b)
{
	if (arith == '*')
		return (a ) * (b );
	else if(arith=='+')
		return (a )+ (b);
	else if (arith == '-')
		return (a) - (b );
}

int Calculate(string& latex,int max_paren)
{
	int arraynum = N - (max_paren * 2);
	vector<int> vec;
	vector<char> ar;
	for (int i = 0; i <= N-1; i++)
	{
		if (parenthesis[i] == true && i<=N-3 && parenthesis[i+2]==true)
		{
			int getnum = simplecal(latex[i]-'0', latex[i + 1], latex[i + 2]-'0');
			i += 2;
			vec.push_back(getnum);
			continue;

		}
		else
		{
			if (latex[i] >= '0' && latex[i] <= '9')
				vec.push_back(latex[i]-'0');
			else
				ar.push_back(latex[i]);
		}
	}
	int getar = vec[0];
	for (int i = 0; i <= vec.size()-2; i++)
	{
		
		getar = simplecal(getar, ar[i], vec[i + 1]);

	}
	return getar;



}
void doDFS(int max_paren, int cur_paren ,string & latex)
{

	if (cur_paren == max_paren)
	{
		int getans = Calculate(latex,max_paren);
		if (getans > cur_max)
			cur_max = getans;
	}
	//add parenthesis
	for (int i = 0; i <= N-3; i+=2)
	{
		if (parenthesis[i] == false && parenthesis[i+2]==false)
		{
			parenthesis[i] = true;
			parenthesis[i + 1] = true;
			parenthesis[i + 2] = true;
			doDFS(max_paren, cur_paren + 1, latex);
			parenthesis[i] = false;
			parenthesis[i + 1] = false;
			parenthesis[i + 2] = false;
		}
	}
	//calculation
	
}

int main()
{
	cin >> N;
	string input;
	cin >> input;
	if (N == 1)
		cout << input[0] - '0';
	else if (N == 3)
	{
		
		cout<< simplecal(input[0] - '0', input[1], input[2] - '0');

	}
	else {
		int t_num = (N + 1) / 2; //total number of integer
		int c_num = N - t_num; //total number of arithmetic operator
		int max_paren = t_num / 2; //maximum number of parenthesis


		for (int i = 0; i <= max_paren; i++)
			doDFS(i, 0, input);
		cout << cur_max;
	}

}