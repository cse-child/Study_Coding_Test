#include <iostream>
#include <string>
#include <vector>
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
		queue<pair<int,int>> que;
		priority_queue<int> importance;
		for(int i = 0; i < N; i++)
		{
			int impo;
			cin >> impo;
			que.push({ i, impo });
			importance.push(impo);
		}

		int cnt = 0;
		while(!que.empty())
		{
			int idx = que.front().first;
			int impo = que.front().second;
			que.pop();
			if (importance.top() == impo)
			{
				cnt++;
				importance.pop();
				if (idx == M)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
				que.push({ idx, impo });
		}
	}

	return 0;
}