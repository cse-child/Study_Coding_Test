/* lower_bound 함수 사용 버전 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int& a : A)
		cin >> a;

	arr.push_back(A[0]);
	for (int i = 1; i < N; i++)
	{
		if (A[i] > arr.back())
			arr.push_back(A[i]);
		else
			*lower_bound(arr.begin(), arr.end(), A[i]) = A[i];
	}
	cout << arr.size();

	return 0;
}


/* 이분탐색 직접 구현 버전 */
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

int BinarySearch(int start, int end, int num)
{
	while(start < end)
	{
		int mid = (start + end) / 2;
		if (num > arr[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int& a : A)
		cin >> a;

	arr.push_back(A[0]);
	int cnt = 1;
	for(int i = 1; i < N; i++)
	{
		if(A[i] > arr.back())
		{
			arr.push_back(A[i]);
			cnt++;
		}
		else
		{
			int idx = BinarySearch(0, cnt, A[i]);
			arr[idx] = A[i];
		}
	}
	cout << cnt;

	return 0;
}
*/