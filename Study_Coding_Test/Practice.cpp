#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

int dp[101][101];

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> weight(N);
	vector<int> value(N);
	for(int i = 0; i < N; i++)
		cin >> weight[i] >> value[i];

	for(int i = 0; i < N; i++)
	{
		for(int j = weight[i]; j < N; j++)
		{
			
		}
	}




	return 0;
}
