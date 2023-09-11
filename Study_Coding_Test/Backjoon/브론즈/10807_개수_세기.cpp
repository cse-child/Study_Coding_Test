#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	unordered_map<int, int> inputs;
	while(N--)
	{
		int temp;
		cin >> temp;
		inputs[temp]++;
	}

	int choice;
	cin >> choice;
	cout << inputs[choice];

	return 0;
}