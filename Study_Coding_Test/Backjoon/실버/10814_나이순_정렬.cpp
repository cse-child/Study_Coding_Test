#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(const pair<int, string> &a, const pair<int, string> &b)
{
	if(a.first != b.first)
		return a.first < b.first;
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> group;
	for(int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		group.emplace_back(age, name);
	}

	stable_sort(group.begin(), group.end(), Compare);

	for (int i = 0; i < N; i++)
		cout << group[i].first << ' ' << group[i].second << '\n';

	return 0;
}