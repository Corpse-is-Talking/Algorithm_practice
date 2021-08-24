#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main()
{
	string input = "";
	cin >> input; //gets thestring

	for (int i = 0; i < input.size(); i++)

	{

		input[i] = toupper(input[i]); //소문자를 대문자로 교환.

	}
	char max_char = input[0];
	int cur_max = 1;
	map<char, int> hash;
	hash[input[0]] = 1;
	for (int i = 1; i < input.size(); i++)
	{
		if (cur_max < hash[input[i]]+1)
		{
			cur_max = hash[input[i]]+1;
			max_char = input[i];
			hash[input[i]] +=1;
            // change if counted more
		}
		else if (cur_max == hash[input[i]] + 1) 
		{ 
			hash[input[i]] += 1;
			max_char = '?';
            //same case..
		}
		else
		{
			hash[input[i]] += 1;
            //just count..
		}
	}
	cout << max_char;



}