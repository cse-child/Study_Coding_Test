#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
	stack<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if (st.empty())
		{
			st.push(s[i]);
			continue;
		}
		if (st.top() == s[i])
			st.pop();
		else
			st.push(s[i]);
	}

	return st.empty() ? 1 : 0;
}

int main()
{
	cout << solution("baaaabb");

	return 0;

}