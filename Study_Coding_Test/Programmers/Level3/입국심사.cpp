#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long low = 1;
	long long high = (long long)times.back() * n;

	sort(times.begin(), times.end());

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long temp = 0;

		for (int i = 0; i < times.size(); i++)
			temp += (mid / times[i]);

		if (temp >= n)
		{
			high = mid - 1;
			answer = mid;
		}
		else
			low = mid + 1;
	}
	return answer;
}