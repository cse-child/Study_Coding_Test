#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<string> word(5);

	for (int i = 0; i < 5; i++)
		cin >> word[i];

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(i < word[j].size())
				cout << word[j][i];
		}
	}
	
	return 0;
}