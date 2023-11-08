#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool Comp(const vector<int>& a, const vector<int>& b)
{
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	stack<int> camera;

	sort(routes.begin(), routes.end(), Comp);
	camera.push(routes[0][1]);

	for (int i = 1; i < routes.size(); i++)
	{
		if (routes[i][0] <= camera.top() && routes[i][1] >= camera.top()) continue;
		camera.push(routes[i][1]);
	}

	return camera.size();
}

int main()
{
	vector<vector<int>> routes = { {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} };
	cout << solution(routes); // 2
}