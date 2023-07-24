#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[10001];
	int top = -1;

	int N;
	cin >> N;
	while(N--)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int temp;
			cin >> temp;
			arr[++top] = temp;
		}
		else if (input == "top")
		{
			if (top < 0)
				cout << "-1" << '\n';
			else
				cout << arr[top] << '\n';
		}
		else if (input == "size")
			cout << top + 1 << '\n';
		else if(input == "empty")
		{
			if (top < 0)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if(input == "pop")
		{
			if (top < 0)
				cout << "-1" << '\n';
			else
				cout << arr[top--] << '\n';
		}
	}

	return 0;
}