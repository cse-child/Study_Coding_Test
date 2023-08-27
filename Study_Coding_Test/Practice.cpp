#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
bool check[9];

void DFS(vector<int>& nums, int num, int start)
{
	if (num == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < N; i++)
	{
		if(!check)
		{
			arr[num] = nums[i];
			DFS(nums, num + 1, i + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<int> nums(N);
	for (int& num : nums)
		cin >> num;

	sort(nums.begin(), nums.end());

	DFS(nums, 0, 0);

	return 0;
}