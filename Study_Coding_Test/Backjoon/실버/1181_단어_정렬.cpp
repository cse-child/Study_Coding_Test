#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

/* vector<string> 정렬 */
//bool comp(string a, string b)
//{
//	if (a.size() == b.size())
//		return a < b;
//	else
//		return a.size() < b.size();
//}

/* priority_queue, set 정렬 */
struct Compare
{
	bool operator() (const string &a, const string &b) const
	{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	set<string, Compare> str;
	for(int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		str.insert(temp);
	}
	cout << endl << endl;

	for (string s : str)
		cout << s << '\n';

	return 0;
}