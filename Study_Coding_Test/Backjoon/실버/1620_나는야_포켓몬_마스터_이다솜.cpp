#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	map<int, string> FindNum;
	map<string, int> FindName;
	for(int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		FindNum[i + 1] = input;
		FindName[input] = i + 1;
	}

	for(int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (input[0] >='0' && input[0] <= '9')
			cout << FindNum[stoi(input)] <<'\n';
		else
			cout << FindName[input] <<'\n';
	}

	return 0;
}