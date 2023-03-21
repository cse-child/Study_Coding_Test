#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	vector<int> copyReserve = reserve;

	for (int num : copyReserve)
	{
		if (find(lost.begin(), lost.end(), num) != lost.end())
		{
			lost.erase(find(lost.begin(), lost.end(), num));
			reserve.erase(find(reserve.begin(), reserve.end(), num));
		}
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		if (reserve[i] - 1 > 0 && find(lost.begin(), lost.end(), reserve[i] - 1) != lost.end())
			lost.erase(find(lost.begin(), lost.end(), reserve[i] - 1));
		else if (reserve[i] + 1 <= n && find(lost.begin(), lost.end(), reserve[i] + 1) != lost.end())
			lost.erase(find(lost.begin(), lost.end(), reserve[i] + 1));
	}

	return n - lost.size();
}