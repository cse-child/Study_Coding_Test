#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long N;
	cin >> N;

	int nums[10001] = { 0 };
	for(long long i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		nums[temp]++;
	}

	for(int i = 0; i < 10001; i++)
	{
		if (nums[i] == 0) continue;

		for (int j = 0; j < nums[i]; j++)
			cout << i << "\n";
	}

	return 0;
}