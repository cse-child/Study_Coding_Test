// 12ºÐ ÄÆ

#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	int curNum = 1;
	stack<int> sub;

	for(int i = 0; i < order.size(); i++)
	{
		if(curNum > order[i])
		{
			if(sub.top() == order[i])
			{
				answer++;
				sub.pop();
				continue;
			}
			break;
		}

		while(order[i] != curNum)
		{
			sub.push(curNum);
			curNum++;
		}
		answer++;
		curNum++;
	}
	return answer;
}