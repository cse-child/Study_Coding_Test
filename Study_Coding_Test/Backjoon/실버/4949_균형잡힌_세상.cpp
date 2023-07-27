#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(true)
	{
		string str;
		getline(cin, str);
		
		if (str == ".") break;

		stack<char> bracket;
		bool No = false;
		for(int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				bracket.push(str[i]);
			else if (str[i] == ')')
			{
				if (!bracket.empty() && bracket.top() == '(')
					bracket.pop();
				else
				{
					No = true;
					break;
				}
			}
			else if(str[i] == ']')
			{
				if(!bracket.empty() && bracket.top() == '[')
					bracket.pop();
				else
				{
					No = true;
					break;
				}
			}
		}
		if (bracket.empty() && !No)
			cout << "yes\n";
		else 
			cout << "no\n";
	}
	return 0;
}

// 그냥 ( 와 ) 의 개수, [ 와 ] 의 개수가 맞으면 되는 줄 알았는데
// ( 가 열리면 ]로 닫히기 전에 ) 로 닫혀야한다는 순서규칙도 지켜져야 함

