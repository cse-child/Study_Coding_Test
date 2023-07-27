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

// �׳� ( �� ) �� ����, [ �� ] �� ������ ������ �Ǵ� �� �˾Ҵµ�
// ( �� ������ ]�� ������ ���� ) �� �������Ѵٴ� ������Ģ�� �������� ��

