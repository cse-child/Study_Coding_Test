#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> s;

	for (int i = 0; i < progresses.size(); i++)
	{
		float publishDay = ceil((100 - progresses[i]) / (float)speeds[i]);

		if (!s.empty() && s.front() < publishDay)
		{
			answer.push_back(s.size());
			while (!s.empty())
				s.pop();
		}
		s.push(publishDay);
	}
	if (!s.empty())
		answer.push_back(s.size());

	return answer;
}