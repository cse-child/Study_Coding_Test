#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	deque<int> q;
	for (int i = 1; i <= N; i++)
		q.push_back(i);

	vector<int> Josephus;
	int idx = K;
	while(Josephus.size() != N)
	{
		for(int i = 0; i < K-1; i++)
		{
			q.push_back(q.front());
			q.pop_front();
		}
		Josephus.push_back(q.front());
		q.pop_front();
	}

	cout << "<";
	for (int i = 0; i < Josephus.size(); i++)
	{
		if (i == Josephus.size() - 1)
			cout << Josephus[i] << ">";
		else
			cout << Josephus[i] << ", ";
	}

	return 0;
}