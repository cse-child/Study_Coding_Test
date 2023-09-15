#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> weight(N);
	for (int& w : weight)
		cin >> w;

	int M;
	cin >> M;
	vector<int> box(M);
	for (int& b : box)
		cin >> b;

	sort(weight.begin(), weight.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	if (weight[0] < box[0])
	{
		cout << "-1";
		return 0;
	}

	int finish = 0;
	while (box.size() != 0)
	{
		vector<bool> check(weight.size());
		for (int i = 0; i < weight.size(); i++)
		{
			if (!check[i])
			{
				for (int j = 0; j < box.size(); j++)
				{
					if (weight[i] >= box[j])
					{
						check[i] = true;
						box.erase(box.begin() + j);
						break;
					}
				}
			}
		}
		finish++;
	}

	cout << finish;
	return 0;
}