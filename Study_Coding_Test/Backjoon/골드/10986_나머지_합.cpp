#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	vector<long long> v(1001);
	long long cnt = 0;
	long long sum = 0;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		v[sum % M]++;
	}

	for(int i = 0; i < v.size(); i++)
		cnt += v[i] * (v[i] - 1) / 2; // nC2
	
	cout << cnt + v[0];

	return 0;
}