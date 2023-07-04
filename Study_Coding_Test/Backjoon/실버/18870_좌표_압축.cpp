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

	vector<int> origin(N);
	for (int& o : origin)
		cin >> o;

	vector<int> copy(origin);
	sort(copy.begin(), copy.end());

	copy.erase(unique(copy.begin(), copy.end()), copy.end());

	for(int i = 0; i < N; i++)
	{
		cout << lower_bound(copy.begin(), copy.end(), origin[i])- copy.begin() << ' ';
	}
	return 0;
}