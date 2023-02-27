#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool isFirstWord = true;

	for (char word : s)
	{
		if (word >= '0' && word <= '9')
			isFirstWord = false;

		if (isFirstWord)
		{
			answer += toupper(word);
			isFirstWord = false;
		}
		else
			answer += tolower(word);

		if (word == ' ')
			isFirstWord = true;
	}
	return answer;
}