#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());

	// index: 1, 2, 3, 4,5,6,7,8
	// nums : 15,12,10,8,6,3,2,1
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] < (i + 1))
			return i;
	}

	return citations.size();
}