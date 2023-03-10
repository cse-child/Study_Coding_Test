#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// https://school.programmers.co.kr/questions/31757

int combination(int n, int r) // nCr = n!/(n-r)!r!
{
	int result = 1;

	for (int i = 0; i < n; i++)
		result *= (n - i);

	for (int i = 0; i < n - r; i++)
		result /= (n - r - i);

	for (int i = 0; i < r; i++)
		result /= (r - i);
	
	return result;
}

int solution(vector<vector<string>> clothes) {
	unordered_map<string, int> divideCloth;

	for (vector<string> cloth : clothes)
		divideCloth[cloth[1]]++;

	int result = 1;
	for(pair<string, int> cloth : divideCloth)
		result *= (combination(cloth.second, 1) + 1);

	return result-1;
}

int main()
{
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
	//vector<vector<string>> clothes = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };

	cout << solution(clothes) << endl;

	cout << combination(2,1) << endl;
}