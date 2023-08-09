#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> nums(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		nums[i] = nums[i - 1] + nums[i];
	}


	while(M--)
	{
		int start, end;
		cin >> start >> end;

		cout << nums[end] - nums[start-1] << '\n';
	}

	return 0;
}