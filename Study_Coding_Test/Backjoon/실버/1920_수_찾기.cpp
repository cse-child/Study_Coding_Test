#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	unordered_map<int, int> nums;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums[temp]++;
	}

	int M;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		if (nums[temp] > 0)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}