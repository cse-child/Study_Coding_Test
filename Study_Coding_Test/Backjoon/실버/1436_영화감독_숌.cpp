#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true)
	{
		int N;
		cin >> N;

		
	}

	return 0;
}

// 666
// 1666
// 2666
// 3666
// 4666
// 5666
// 6666
// 6667
// 6668
// 6669
// 10666
// 11666, 16661, 66611
// 12666
// 13666
// 14666
// 15666
// 16666
// 16667

/*

string num = "0";
		for (int i = 0; i <= N; i++)
		{
			// 17 666, 1 666 7, 666 17
			string temp = to_string(i - 1);
			int minNum = stoi("666"+temp);
			for(int j = 1; j <= temp.length(); j++)
			{
				string str = temp.substr(0, j) + "666" + temp.substr(j, temp.length());
				if (stoi(str) < minNum)
					minNum = stoi(str);
			}
			num = to_string(minNum);
		}
		cout << stoi(num) << "\n\n";
 
 */

// 17666, 16667, 66617
// 66610, 16660, 10666