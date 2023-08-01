#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> Importance(N);
		queue<int> que;
		for (int& i : Importance)
		{
			cin >> i;
			que.push(i);
		}

		int cnt = 0;
		while(true)
		{
			int MaxIdx = max_element(Importance.begin(), Importance.end()) - Importance.begin();
			
			while (que.front() != Importance[MaxIdx])
			{
				que.push(que.front());
				que.pop();
			}

			que.pop(); // ¿Œº‚
			cnt++;
			Importance[MaxIdx] = 0;

			if (MaxIdx == M)
			{
				cout << cnt << '\n';
				break;
			}
		}
	}

	return 0;
}