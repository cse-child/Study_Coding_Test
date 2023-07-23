#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


// https://gusdnr69.tistory.com/99
bool Comp(const pair<string, int> a, pair<string, int> b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		else
			return a.first.length() > b.first.length();
	}
	else
		return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> inputs;

	while(N--)
	{
		string input;
		cin >> input;
		if (input.length() >= M)
			inputs[input]++;
	}

	vector<pair<string, int>> words(inputs.begin(), inputs.end());

	sort(words.begin(), words.end(), Comp);

	for (pair<string, int> word : words)
		cout << word.first << '\n';

	return 0;
}