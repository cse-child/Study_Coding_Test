#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<char> result;
	stack<int> st;
	int idx = 1;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while(idx <= num)
		{
			st.push(idx);
			idx++;
			result.push_back('+');
		}

		if(st.top() == num)
		{
			st.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (char r : result)
		cout << r << '\n';

	return 0;
}