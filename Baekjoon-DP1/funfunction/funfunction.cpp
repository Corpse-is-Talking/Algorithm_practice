#include<iostream>
#include<cstring>
using namespace std;
int	arr[51][51][51] = {0};

int calculator(int a, int b, int c)
{
	
    //base case
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
    //if inthe memory, dont do the recursion
	if (arr[a][b][c]!=0)
	{
		return arr[a][b][c];
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		if (arr[20][20][20] != 0) 
		{
			arr[a][b][c] = arr[20][20][20];
			return arr[20][20][20]; 
		}
		else {
			arr[20][20][20] = calculator(20, 20, 20);
			arr[a][b][c] = arr[20][20][20];
			return arr[20][20][20];
		}
	}
    //the other case
	else if (a < b && b < c)
	{
		arr[a][b][c]= calculator(a, b, c - 1) + calculator(a, b - 1, c - 1) - calculator(a, b - 1, c);
		return arr[a][b][c];
	}
	else
	{
		arr[a][b][c]= calculator(a - 1, b, c) + calculator(a - 1, b - 1, c) + calculator(a - 1, b, c - 1) - calculator(a - 1, b - 1, c - 1);
		return arr[a][b][c];
	}
		 
	return 0;
}
int main()
{
	int a = 0, b = 0, c = 0;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		else
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << calculator(a, b, c) << endl;

		}
	}
		
}