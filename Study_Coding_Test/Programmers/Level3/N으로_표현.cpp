#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	if (N == number) return 1;
	unordered_set<int> dp[8];

	/*
	 5를 1번 사용 : 5
	 5를 2번 사용 : 55, 5+5, 5-5, 5*5, 5/5
	 5를 3번 사용 : 555, 5+(5+5), 5-(5+5), 5*(5+5), 5/(5+5)
						5+(5-5), 5-(5-5), 5*(5-5), 5/(5-5)
						5+(5*5), 5-(5*5), 5*(5*5), 5/(5*5)
						5+(5/5), 5-(5/5), 5*(5/5), 5/(5/5)

						55+5, 55-5, 55*5, 55/5
						5+55, 5-55, 5*55, 5/55
	 */

	string s = "";
	for(int i = 0; i < 8; i++)
	{
		s += to_string(N);
		dp[i].insert(stoi(s));
	}

	for(int i = 1; i < 8; i++)
	{
		for(int j = 0; j < i; j++)
		{
			for(int a : dp[j])
			{
				for(int b : dp[i-j-1])
				{
					dp[i].insert(a + b);
					dp[i].insert(a - b);
					dp[i].insert(a * b);
					if (b != 0)
						dp[i].insert(a / b);
				}
			}
		}
	}

	for(int i = 0; i < 8; i++)
	{
		if (dp[i].find(number) != dp[i].end())
			return i + 1;
	}
	return -1;
}

int main()
{
	cout << solution(5, 12);
}