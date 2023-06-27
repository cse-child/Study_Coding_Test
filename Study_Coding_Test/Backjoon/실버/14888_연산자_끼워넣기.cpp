#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;
int arr[12];
int oper[4];
long long nums[2] = { -1000000001, 1000000001 }; // min, max

void DFS(int depth, long long result)
{
	if(depth == N+1)
	{
		nums[0] = nums[0] < result ? result : nums[0];
		nums[1] = nums[1] > result ? result : nums[1];
		//cout << " = " << result << endl << arr[1];
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		if (oper[i] == 0) continue;

		oper[i]--;
		switch (i)
		{
		case 0:
			DFS(depth + 1, result+arr[depth]);
			//cout << "+" << arr[depth];
			break;
		case 1:
			DFS(depth + 1, result - arr[depth]);
			//cout << "-" << arr[depth];
			break;
		case 2:
			DFS(depth + 1, result * arr[depth]);
			//cout << "*" << arr[depth];
			break;
		case 3:
			DFS(depth + 1, result / arr[depth]);
			//cout << "/" << arr[depth];
			break;
		}
		oper[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++) // +, -, x, /
		cin >> oper[i];

	//cout << endl << arr[1];

	DFS(2, arr[1]);
	
	cout << nums[0] << ' ' << nums[1];

	return 0;
}