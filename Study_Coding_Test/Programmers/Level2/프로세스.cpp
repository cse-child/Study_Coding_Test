#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	priority_queue<int> pq(priorities.begin(), priorities.end());
	vector<bool> check(priorities.size());
	int clear = 0;
	int index = 0;

	while(clear < priorities.size())
	{
		if(priorities[index] == pq.top() && !check[index])
		{
			check[index] = true;
			clear++;
			pq.pop();

			if (index == location)
				return clear;
		}

		index = index + 1 >= priorities.size() ? 0 : index + 1;
	}
	return clear;
}

int main()
{
	//vector<int> priorities = { 2, 1, 3, 2 };
	vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
	cout << solution(priorities, 0) << endl;
}