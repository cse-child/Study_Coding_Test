#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> nums(N);
	for (int& num : nums)
		cin >> num;

	sort(nums.begin(), nums.end());

	for (int num : nums)
		cout << num << '\n';

	return 0;
}