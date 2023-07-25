#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	stack<int> s;
	int sum = 0;

	int K;
	cin >> K;
	while(K--)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			sum -= s.top();
			s.pop();
		}
		else
		{
			s.push(input);
			sum += s.top();
		}
	}
	cout << sum;
	return 0;
}