#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int aCnt, bCnt;
	cin >> aCnt >> bCnt;

	vector<int> A(aCnt);
	for (int& a : A)
		cin >> a;
	vector<int> B(bCnt);
	for (int& b : B)
		cin >> b;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int result = 0;
	vector<int> diff(aCnt + bCnt);
	auto iter = set_difference(A.begin(), A.end(), B.begin(), B.end(), diff.begin());
	diff.erase(iter, diff.end());
	result += diff.size();

	diff.clear();
	diff.resize(aCnt + bCnt);
	iter = set_difference(B.begin(), B.end(), A.begin(), A.end(), diff.begin());
	diff.erase(iter, diff.end());
	result += diff.size();

	cout << result;
	return 0;
}