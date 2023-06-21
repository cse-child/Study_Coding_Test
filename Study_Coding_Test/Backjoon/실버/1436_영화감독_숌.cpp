#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int i = 666;
	int cnt = 0;

	while(true)
	{
		string str = to_string(i);
		for(int i = 0; i < str.length()-2; i++)
		{
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				cnt++;
				if (cnt == N)
				{
					cout << str;
					return 0;
				}
				break;
			}
		}
		i++;
	}
	return 0;
}