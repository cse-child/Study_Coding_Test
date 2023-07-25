#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		string input;
		cin >> input;
		stack<int> vps;
		bool isNo = false;
		for(int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(')
				vps.push(1);
			else if (input[i] == ')')
			{
				if (vps.empty())
				{
					cout << "NO\n";
					isNo = true;
					break;
				}
				vps.pop();
			}
		}
		if (isNo) continue;
		if (vps.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}