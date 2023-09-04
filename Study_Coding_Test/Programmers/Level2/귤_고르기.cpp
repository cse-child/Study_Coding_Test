#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
	map<int, int> type;
	for (int t : tangerine)
		type[t]++;

	vector<int> cnts;
	for (auto t : type)
		cnts.push_back(t.second);

	sort(cnts.begin(), cnts.end(), greater<>());

	int typeCnt = 0;
	for (int i = 0; i < cnts.size(); i++)
	{
		k -= cnts[i];
		typeCnt++;

		if (k <= 0) break;
	}
	return typeCnt;
}

int main()
{
	vector<int> arr = { 1,3,2,5,4,5,2,3 };
	//vector<int> arr = { 1, 3, 2, 5, 4, 5, 2, 3 };
	//vector<int> arr = { 1, 1, 1, 1, 2, 2, 2, 3 };
	//vector<int> arr = { 9999999,10000000};


	cout << solution(6, arr);
}