#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> nums(N);
	double sum = 0; // float으로 선언하면 틀림
	vector<int> counts(8001);
	for (int& num : nums)
	{
		cin >> num;
		sum += num;
		counts[num + 4000]++;
	}

	sort(nums.begin(), nums.end());
	
	cout << int(round(sum / N)) << '\n'; // int 로 안묶으면 틀림
	cout << nums[(double)N / 2] << '\n'; // double로 하는게 더 빠름

	int maxNum = *max_element(counts.begin(), counts.end());
	int maxCnt = 0;
	int result = 0;
	for(int i = 0; i <= 8000; i++) // 0 이 아닌 1부터 시작하면 65% 정답에서 멈춤
	{
		if (counts[i] == maxNum)
		{
			maxCnt++;
			result = i - 4000;
		}
		if (maxCnt >= 2)
			break;
	}
	cout << result << '\n';
	cout << nums[N - 1] - nums[0] << '\n';

	return 0;
}