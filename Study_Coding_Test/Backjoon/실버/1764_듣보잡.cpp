#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	map<string, int> p;
	vector<string> v;
	int N, M;

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		p[input]++;
	}
	for(int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (p[input] > 0)
			v.push_back(input);
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (string s : v)
		cout << s << '\n';

	return 0;
}