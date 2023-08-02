#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	deque<int> dq;

	int N;
	cin >> N;
	while(N--)
	{
		string str;
		cin >> str;

		if (str == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "front")
		{
			if (!dq.empty())
				cout << dq.front() << '\n';
			else
				cout << "-1\n";
		}
		else if (str == "back")
		{
			if (!dq.empty())
				cout << dq.back() << '\n';
			else
				cout << "-1\n";
		}
		else if (str == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
			cout << dq.size() << '\n';
		else if (str == "empty")
			cout << dq.empty() << '\n';
	}
	return 0;
}