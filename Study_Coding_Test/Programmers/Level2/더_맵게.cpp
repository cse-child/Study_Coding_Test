#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// ����.. 16����
int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pd(scoville.begin(), scoville.end());

	while (pd.top() < K)
	{
		int scovil = pd.top();
		pd.pop();

		if (pd.size() < 1)
			return -1;

		scovil += (pd.top() * 2);
		pd.pop();

		pd.push(scovil);
		answer++;
	}
	return answer;
}