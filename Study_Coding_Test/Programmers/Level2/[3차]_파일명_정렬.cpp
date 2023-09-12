#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<string> SplitFileName(const string& name)
{
	vector<string> result;

	bool isNum = false;
	int startIdx = 0, endIdx = 0;
	for(int i = 0; i < name.size(); i++)
	{
		if(name[i] >= '0' && name[i] <= '9')
		{
			if(!isNum)
			{
				isNum = true;
				startIdx = i;
			}
		}
		else
		{
			if(isNum)
			{
				endIdx = i;
				break;
			}
		}
	}

	string temp;
	for(int i = 0; i < startIdx; i++)
		temp.push_back(tolower(name[i]));
	
	result.push_back(temp);
	result.push_back(name.substr(startIdx, endIdx - startIdx));

	return result;
}

bool Comp(const tuple<string, string, int>& t1, const tuple<string, string, int>& t2)
{
	if (get<1>(t1) == get<1>(t2))
	{
		return get<2>(t1) < get<2>(t2);
	}
	return get<1>(t1) < get<1>(t2);
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector <tuple<string, string, int>> FileList;

	for(int i = 0; i < files.size(); i++)
	{
		vector<string> splitStr = SplitFileName(files[i]);
		tuple<string, string, int> temp(files[i], splitStr[0], stoi(splitStr[1]));
		FileList.push_back(temp);
	}

	stable_sort(FileList.begin(), FileList.end(), Comp);

	for (auto file : FileList)
		answer.push_back(get<0>(file));

	return answer;
}

int main()
{
	vector<string> files = { "IMg12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	solution(files);
}