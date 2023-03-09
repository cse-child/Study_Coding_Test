#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> p, c;
	for (string name : participant)
		p[name]++;
	for (string name : completion)
		c[name]++;

	for (string name : participant)
	{
		if (c.count(name) == 0) return name;
		if (p[name] > c[name]) return name;
	}
	return "";
}