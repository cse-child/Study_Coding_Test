#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> result(numbers.size());
	vector<pair<int, int>> nums;
	for (int i = 0; i < numbers.size(); i++)
		nums.emplace_back(numbers[i], i);

	// 9 1 5 3 6 2
	// 0 1 2 3 4 5

	// 1 2 3 5 6 9
	// 1 5 3 2 4 0

	sort(nums.begin(), nums.end());

	for(int i = 0; i < numbers.size(); i++)
	{
		int idx = nums[i].second + 1;
		int findIdx = find(nums.begin()->second, nums.end()->second, idx) - nums.begin()->second;
		cout << findIdx << " ";
	}
	

	return result;
}

int main()
{
	//vector<int> numbers = { 2,3,3,5 };
	vector<int> numbers = { 9,1,5,3,6,2 };
	solution(numbers);
}