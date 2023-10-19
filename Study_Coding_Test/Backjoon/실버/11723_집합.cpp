#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M;
	cin >> M;

	string str;
	int x;
	int S = 0;
	for(int i = 0; i < M; i++)
	{
		cin >> str;

		if(str == "add")
		{
			cin >> x;
			S |= (1 << x);
		}
		else if(str == "check")
		{
			cin >> x;
			if (S & (1 << x))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if(str == "remove")
		{
			cin >> x;
			S &= ~(1 << x);
		}
		else if(str == "toggle")
		{
			cin >> x;
			if (S & (1 << x))
				S &= ~(1 << x);
			else
				S |= (1 << x);
		}
		else if(str == "all")
			S = (1 << 21) - 1;
		else if(str == "empty")
			S = 0;
	}
	return 0;
}