#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

// 연속된!!!!!!!!!!!!!!!세그먼트를 구해야함 ㅠㅠ  문제 제대로 읽자
int birthday(vector<int> s, int d, int m) {
	int sum = accumulate(s.begin(), s.begin() + m, 0);
	int result = 0;
	if (sum == d) result++;

	for(int i = m; i < s.size(); i++)
	{
		sum += s[i];
		sum -= s[i - m];
		if (sum == d) result++;
	}
	return result;
}