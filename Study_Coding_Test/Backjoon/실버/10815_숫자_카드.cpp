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
	vector<int> SangCard(N);
	for (int& c : SangCard)
		cin >> c;

	int M;
	cin >> M;
	vector<int> Card(M);
	for (int& c : Card)
		cin >> c;

	sort(SangCard.begin(), SangCard.end());

	for(int i = 0; i < M; i++)
		cout << binary_search(SangCard.begin(), SangCard.end(), Card[i]) <<' ';
	return 0;
}