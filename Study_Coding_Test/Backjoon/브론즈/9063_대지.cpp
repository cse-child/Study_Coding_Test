#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	/* vector 안쓰는 버전 */
	int minX = 10001;
	int maxX = -10001;
	int minY = 10001;
	int maxY = -10001;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	cout << (maxX - minX) * (maxY - minY) << endl;

	/* vector 쓰는 버전 */
	//vector<int> X(N);
	//vector<int> Y(N);
	//for (int i = 0; i < N; i++)
	//	cin >> X[i] >> Y[i];
	//
	//int size = (*max_element(X.begin(), X.end()) - *min_element(X.begin(), X.end())) *
	//	(*max_element(Y.begin(), Y.end()) - *min_element(Y.begin(), Y.end()));
	//
	//cout << size << endl;
	return 0;
}