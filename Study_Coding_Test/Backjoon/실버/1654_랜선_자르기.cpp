#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> lan;
long long K, N;

long long SliceLANCount(int size)
{
	long long cnt = 0;
	for(int i = 0; i < lan.size(); i++)
		cnt += (lan[i] / size);

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> K >> N;

	lan.resize(K);
	for (long long& l : lan)
		cin >> l;

	long long start = 1;
	long long end = *max_element(lan.begin(), lan.end())+1;
	long long result = 0;

	while(start <= end)
	{
		long long mid = (start + end) / 2;

		if (SliceLANCount(mid) >= N)
		{
			start = mid + 1;
			result = max(result, mid); // 없으면 실패!
		}
		else
			end = mid - 1;
	}

	cout << result;

	return 0;
}