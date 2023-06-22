#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	vector<int> nums(5);
	for (int& n : nums)
	{
		cin >> n;
		sum += n;
	}

	sort(nums.begin(), nums.end());

	cout << (sum / 5) << '\n' << nums[2];

	return 0;
}