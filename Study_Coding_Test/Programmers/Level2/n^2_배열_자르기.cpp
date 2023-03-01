#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	for (int i = (left / n); i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long idx = (i * n) + j;
			if (idx > right) break;
			if (idx < left) continue;

			if (i > j)
				answer.push_back(i + 1);
			else
				answer.push_back(j + 1);
		}
	}
	return answer;
}

int main(void)
{
	//solution(3, 2, 5);
	solution(4, 7, 14);
	return 0;
}