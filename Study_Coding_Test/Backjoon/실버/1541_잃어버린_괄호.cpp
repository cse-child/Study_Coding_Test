#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	vector<int> num;
	vector<char> oper;
	string numStr = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			num.push_back(stoi(numStr));
			oper.push_back(str[i]);
			numStr = "";
		}
		else
			numStr += str[i];
	}
	num.push_back(stoi(numStr));
	
	for(int i = 0; i < oper.size(); i++)
	{
		if(oper[i] == '-')
		{
			
		}
	}

	int i = 0;

	return 0;
}