// 4Ка
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> money{500, 100, 50, 10, 5, 1};

	int pay;
	cin >> pay;
	pay = 1000 - pay;

	int cnt = 0;
	for(int i = 0; i < money.size(); i++)
	{
		if (pay <= 0) break;
		cnt += pay / money[i];
		pay %= money[i];
	}
	cout << cnt;
	return 0;
}