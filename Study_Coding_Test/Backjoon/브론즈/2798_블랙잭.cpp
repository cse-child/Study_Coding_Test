#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> card(N);
	for (int& c : card)
		cin >> c;

	int minDiff = M;
	int minSum = 0;
	int sum = 0;
	for(int i = 0; i < N-2; i++)
	{
		for(int j = i+1; j < N-1; j++)
		{
			for(int k = j+1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (M - sum >= 0 && M - sum < minDiff)
				{
					minDiff = M - sum;
					minSum = sum;
					cout << card[i] << " " << card[j] << " " << card[k] << endl;
				}
			}
		}
	}

	cout << minSum;
	return 0;
}


// 브루트 포스(무식한 힘,,)
// N 입력값을 보고 1억번을 1초로 생각해서
// 모든 경우의 수를 다 계산한 시간을 보고 판별