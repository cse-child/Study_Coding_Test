#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> nums(N);
	for (int& num : nums)
		cin >> num;

	bool check[1001];
	memset(check, true, sizeof(check));
	check[0] = check[1] = false;

	int maxNum = *max_element(nums.begin(), nums.end());
	for(int i = 2; i <= sqrt(maxNum); i++)
	{
		if(check[i])
		{
			for (int j = i + i; j <= maxNum; j += i)
				check[j] = false;
		}
	}

	int cnt = 0;
	for(int i = 2; i <= maxNum; i++)
	{
		if (check[i] && find(nums.begin(), nums.end(), i) != nums.end())
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}