#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long N, M;

long long CutTree(vector<long long>& tree, long long size)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] - size > 0)
			sum += tree[i] - size;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<long long> tree(N);
	for (long long& t : tree)
		cin >> t;

	sort(tree.begin(), tree.end(), greater<long long>());

	long long result = 0;
	long long start = tree[0] - M;
	long long end = tree[0];
	while (start < end)
	{
		long long mid = (start + end) / 2;
		if (CutTree(tree, mid) > M)
		{
			if (mid > result)
				result = mid;
			start = mid + 1;
		}
		else if (CutTree(tree, mid) < M)
			end = mid;
		else
		{
			result = mid;
			break;
		}
	}

	cout << result;
	return 0;
}