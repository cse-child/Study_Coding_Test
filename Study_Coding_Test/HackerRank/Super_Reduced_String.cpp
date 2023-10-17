#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;


string superReducedString(string s) {
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			s.erase(s.begin() + i);
			s.erase(s.begin() + i);

			if (s.length() == 0) break;

			i = -1;
		}
	}

	if (s.length() == 0)
		s = "Empty String";

	return s;
}


int main()
{
	cout << superReducedString("baab");
}