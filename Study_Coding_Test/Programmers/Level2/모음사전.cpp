// 참조 사이트
// https://html-jc.tistory.com/688

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string word) {
	int result = 0;
	unordered_map<char, int> one, two, three, four, five;
	five['A'] = 1;
	five['E'] = 2;
	five['I'] = 3;
	five['O'] = 4;
	five['U'] = 5;

	four['A'] = 1;
	four['E'] = 7;
	four['I'] = 13;
	four['O'] = 19;
	four['U'] = 25;

	three['A'] = 1;
	three['E'] = 32;
	three['I'] = 63;
	three['O'] = 94;
	three['U'] = 125;

	two['A'] = 1;
	two['E'] = 157;
	two['I'] = 313;
	two['O'] = 469;
	two['U'] = 625;

	one['A'] = 1;
	one['E'] = 782;
	one['I'] = 1563;
	one['O'] = 2344;
	one['U'] = 3125;

	result += one[word[0]];
	if (word.size() >= 2)
		result += two[word[1]];
	if (word.size() >= 3)
		result += three[word[2]];
	if (word.size() >= 4)
		result += four[word[3]];
	if (word.size() >= 5)
		result += five[word[4]];

	return result;
}

int main()
{
	solution("AAAE");
}

/* 좋은 풀이 */
/*
int solution(string word)
{
	// weights는 문자열의 자릿수 별 경우의 수를 나타낸 것
	// 5개의 단어이므로, 5 제곱씩 늘어나는 수를 더하면 된다.
	// 1
	// 6 = 1 + 5
	// 31 = 6 + (5*5)
	// 156 = 31 + (5*5*5)
	// 781 = 156 + (5*5*5*5)
	const int weights[5] = { 781, 156, 31, 6, 1 };
	int answer = 0;
	for (int i = 0; i < word.length(); ++i)
	{
		int current;
		switch (word[i])
		{
		case 'A':
			current = 0;
			break;
		case 'E':
			current = 1;
			break;
		case 'I':
			current = 2;
			break;
		case 'O':
			current = 3;
			break;
		case 'U':
			current = 4;
			break;
		default:
			assert(false);
		}
		++answer;
		answer += current * weights[i];
	}
	return answer;
}
*/