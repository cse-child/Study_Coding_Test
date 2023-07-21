#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int result = 1;
	unordered_map<string, bool> people;
	people["ChongChong"] = true;

	int N;
	cin >> N;
	while(N--)
	{
		string A, B;
		cin >> A >> B;
		if (people[A] ^ people[B])
		{
			people[A] = people[B] = true;
			result++;
		}
	}

	cout << result;
	return 0;
}