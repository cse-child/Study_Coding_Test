#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> str;

	while(true)
	{
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		if (m % n == 0)
			str.push_back("factor");
		else if (n % m == 0)
			str.push_back("multiple");
		else
			str.push_back("neither");
	}

	for (string s : str)
		cout << s << "\n";

	return 0;
}