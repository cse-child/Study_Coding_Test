// https://school.programmers.co.kr/questions/31757

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

long long combination(int n, int r) // nCr = n!/(n-r)!r!
{
	long long result = 1;

	for (int i = 0; i < n; i++)
		result *= (n - i);

	for (int i = 0; i < n - r; i++)
		result /= (n - r - i);

	for (int i = 0; i < r; i++)
		result /= (r - i);

	return result;
}

int solution(vector<vector<string>> clothes) {
	map<string, int> divideCloth;

	for (vector<string> cloth : clothes)
		divideCloth[cloth[1]]++;

	long long result = 1;
	//for(pair<string, int> cloth : divideCloth)
	//	result *= (combination(cloth.second, 1) + 1);

	for (pair<string, int> cloth : divideCloth)
		result = result * (cloth.second + 1);

	return result - 1;
}