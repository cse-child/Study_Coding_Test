#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> fly;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			fly.emplace_back(a, b);
		}

		// ��.. �׳� �ּ� ���� ��...����ϸ�..��...
		// Union-Find...�ϰ�,,�������µ�...
		cout << N - 1 << '\n';
	}
	return 0;
}