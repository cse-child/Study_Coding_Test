#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

// ���ӵ�!!!!!!!!!!!!!!!���׸�Ʈ�� ���ؾ��� �Ф�  ���� ����� ����
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