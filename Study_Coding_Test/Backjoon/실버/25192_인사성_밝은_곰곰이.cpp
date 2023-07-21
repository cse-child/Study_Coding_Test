#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	map<string, bool> people;
	int result = 0;

	int N;
	cin >> N;
	while(N--)
	{
		
		string input;
		cin >> input;
		if(input == "ENTER")
			people.erase(people.begin(), people.end());
		else
		{
			if(!people[input])
			{
				result++;
				people[input] = true;
			}
		}
	}

	cout << result;
	return 0;
}