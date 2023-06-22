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

	vector<int> times(N);
	for (int& time : times)
		cin >> time;

	sort(times.begin(), times.end());

	// 1,2,3,3,4
	// 1,3,6,9,13 = 32

	// 1
	// 1 + (1+2) = 4
	// 4 + (1+2+3) = 10
	// 10 + (1+2+3+3) = 19
	// 19 + (1+2+3+3+4) = 32
	int sum = 0;
	int tempSum = 0;
	for (int i = 0; i < times.size(); i++)
	{
		tempSum += times[i];
		sum += tempSum;
	}
	cout << sum;
	return 0;
}