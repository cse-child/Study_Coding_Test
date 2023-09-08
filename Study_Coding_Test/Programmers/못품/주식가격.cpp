#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());

	
	for(int i = 1; i < prices.size(); i++)
	{
		
	}

	stack<int> stack;
	stack.push(prices[prices.size()-1]);
	answer[prices.size() - 1] = 0;
	for(int i = prices.size()-2; i >= 0; i--)
	{
		if(prices[i] <= stack.top())
		{
			answer[i]++;
			stack.push(prices[i]);
		}

	}

	return answer;
}