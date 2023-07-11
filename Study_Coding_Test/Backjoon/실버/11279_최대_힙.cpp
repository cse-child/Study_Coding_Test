#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>> pq;
	for(int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		if (input != 0)
			pq.push(input);
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
	}

	return 0;
}