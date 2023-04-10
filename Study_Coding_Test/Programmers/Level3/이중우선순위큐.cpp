#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	priority_queue<int> maxPQ;
	priority_queue<int, vector<int>, greater<int>> minPQ;
	int count = 0;

	for (string operation : operations)
	{
		if (operation.find("I") == 0)
		{
			maxPQ.push(stoi(operation.substr(1)));
			minPQ.push(stoi(operation.substr(1)));
			count++;
		}
		else if (operation == "D 1" && !maxPQ.empty() && count > 0)
		{
			maxPQ.pop();
			count--;
		}
		else if (operation == "D -1" && !minPQ.empty() && count > 0)
		{
			minPQ.pop();
			count--;
		}

		if (count == 0)
		{
			while (!maxPQ.empty())
				maxPQ.pop();

			while (!minPQ.empty())
				minPQ.pop();
		}
	}

	if (count == 1)
	{
		if (maxPQ.empty())
			return vector<int>{minPQ.top(), minPQ.top()};
		if (minPQ.empty())
			return vector<int>{maxPQ.top(), maxPQ.top()};
	}
	else if (count > 1)
		return vector<int>{maxPQ.top(), minPQ.top()};
	else
		return vector<int>{0, 0};
}