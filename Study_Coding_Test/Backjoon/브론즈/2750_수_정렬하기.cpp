#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> nums(N);
	for(int& n : nums)
		cin >> n;

	sort(nums.begin(), nums.end());

	for (int n : nums)
		cout << n << '\n';
	return 0;
}