#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1000001];

// for문 2개 쓰는 버전
int solution(vector<int> money) {
	int answer = 0;

	// 첫번째 집을 방문하는 경우 => 마지막 집 방문 안함
	dp[0] = money[0];
	dp[1] = max(money[0], money[1]);

	for (int i = 2; i < money.size(); i++)
	{
		if (i == money.size() - 1) // 마지막 집 방문 X
		{
			dp[i] = dp[i - 1];
			continue;
		}
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
	}

	answer = dp[money.size() - 1];

	// 첫번째 집을 방문하지 않는 경우 => 마지막 집은 방문 할수도 있고, 안할수도 있고
	dp[0] = 0;
	dp[1] = money[1];
	for (int i = 2; i < money.size(); i++)
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);

	answer = max(answer, dp[money.size() - 1]);

	return answer;
}

/*		배열 2개 쓰는 버전
int solution(vector<int> money) {
	vector<int> one(money.size(), money[0]), two(money.size(), money[1]);
	vector<int> m1(money.begin()+1, money.end());
	m1.insert(m1.begin(), 0);
		
	vector<int> m2(money.begin(), money.end()-1);
	m2.insert(m2.begin(), 0);

	vector<int> dp1(m1.size() + 1);
	dp1[1] = m1[0];
	dp1[2] = m1[1];

	vector<int> dp2(money.size() + 1);
	dp2[1] = m2[0];
	dp2[2] = m2[1];

	for (int i = 3; i <= m1.size(); i++)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + m1[i - 1]);
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + m2[i - 1]);
	}

	return max(dp1[money.size()], dp2[money.size()]);
}
*/

int main()
{
	//vector<int> money = { 1,3,5,7,4 }; // 10
	//vector<int> money = { 1,2,3,1 }; // 4
	//vector<int> money = { 1,2,3,4,5,6,7,8 }; // 20
	//vector<int> money = { 1000,10,10,2000,30 }; // 3000
	//vector<int> money = { 1,10,20,4,40 }; // 60
	//vector<int> money = { 10,5,3,1,10 }; // 15
	//vector<int> money = { 1,2,3 };  // 3
	//vector<int> money = { 0,0,2,1,0,0,1 };  // 3
	//vector<int> money = { 10,2,2,100,2 };  // 110
	//vector<int> money = { 4,1,4,1,4 };  // 8
	vector<int> money = { 999,0,0 };  // 8

	cout << solution(money);
}