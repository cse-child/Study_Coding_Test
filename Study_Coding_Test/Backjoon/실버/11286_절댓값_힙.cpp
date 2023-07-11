#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Compare
{
	bool operator() (int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, Compare> pq;
	for(int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input != 0)
			pq.push(input);
		else
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	
	return 0;
}