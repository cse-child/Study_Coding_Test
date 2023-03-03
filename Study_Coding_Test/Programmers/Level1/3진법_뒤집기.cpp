#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
	int answer = 0;
	string three = "";

	while (n > 0)
	{
		three += to_string((n % 3));
		n = n / 3;
	}

	for (int i = 0; i < three.length(); i++)
		answer += ((three[i] - '0') * pow(3, three.length() - 1 - i));

	return answer;
}