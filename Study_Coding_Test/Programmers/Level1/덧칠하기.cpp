#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int paint = 1;
	int curPaint = section[0] + m;

	for(int i = 0; i < section.size(); i++)
	{
		if (section[i] < curPaint)
			continue;

		curPaint = section[i] + m;
		paint++;
	}

	return paint;
}

int main()
{
	vector<int> section = { 1,4,5 };
	cout << solution(5, 2, section); // 2
}