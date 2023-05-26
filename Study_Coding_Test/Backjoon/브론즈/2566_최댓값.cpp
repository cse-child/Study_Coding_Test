#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums(81);
	
	for (int& num : nums)
		cin >> num;

	cout << *max_element(nums.begin(), nums.end()) << endl;
	
	int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
	cout << (maxIdx / 9+1) << " ";
	cout << (maxIdx % 9+1) << endl;
	
	return 0;
}