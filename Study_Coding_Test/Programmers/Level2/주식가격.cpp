#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> st;

	st.push(0);

	for (int i = 1; i < prices.size(); i++)
	{
		while (!st.empty())
		{
			int top = st.top();
			if (prices[top] <= prices[i]) break;
			st.pop();
			answer[top] = i - top;
		}
		st.push(i);
	}

	while (!st.empty())
	{
		answer[st.top()] = prices.size() - st.top() - 1;
		st.pop();
	}
	return answer;
}

int main()
{
	vector<int> prices = { 1,2,3,2,3 };
	solution(prices);
}