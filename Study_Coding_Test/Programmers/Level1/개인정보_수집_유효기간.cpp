#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

// 0: year, 1: month, 2: day
int GetCalendar(int key, string date)
{
	vector<string> calendar;
	stringstream ss(date);
	string temp;

	while (getline(ss, temp, '.'))
		calendar.push_back(temp);

	switch (key)
	{
	case 0:
		return stoi(calendar[0]);
	case 1:
		return stoi(calendar[1]);
	case 2:
		return stoi(calendar[2]);
	}
	return 0;
}

int GetDiffDate(string start, string end)
{
	int diffYear = 0, diffMonth = 0, diffDays = 0;
	int resultDays = 0;

	diffYear = GetCalendar(0, end) - GetCalendar(0, start);
	diffMonth = GetCalendar(1, end) - GetCalendar(1, start);
	diffDays = GetCalendar(2, end) - GetCalendar(2, start);

	if (diffDays < 0)
	{
		diffMonth--;
		resultDays += (28 + diffDays);
	}
	else
		resultDays += diffDays;

	if (diffMonth < 0)
	{
		diffYear--;
		resultDays += ((12 + diffMonth) * 28);
	}
	else
		resultDays += (diffMonth * 28);

	if (diffYear < 0)
		return -1;
	else
		resultDays += (diffYear * 12 * 28);

	return resultDays;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	map<string, int> termsMap;

	for(string term : terms)
		termsMap[term.substr(0, 1)] = stoi(term.substr(2));

	int num = 1;
	for(string privacy : privacies)
	{
		string collectionDate = privacy.substr(0, 10);
		string term = privacy.substr(privacy.length() - 1);

		if (GetDiffDate(collectionDate, today) >= (termsMap[term] * 28))
			answer.push_back(num);
		num++;
	}

	return answer;
}

int main()
{
	//cout << GetCalendar(2, "2022.05.19");

	//string today = "2022.05.19";
	//vector<string> terms = { "A 6", "B 12", "C 3" };
	//vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

	string today = "2020.01.01";
	vector<string> terms = { "Z 3", "D 5" };
	vector<string> privacies = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };

	solution(today, terms, privacies);
}