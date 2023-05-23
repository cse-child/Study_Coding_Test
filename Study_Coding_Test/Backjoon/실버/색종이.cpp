#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define WIDTH 10

using namespace std;

int main()
{
	bool area[100][100] = { false };
	int totalArea = 0;
	int paperCnt;

	cin >> paperCnt;

	for(int i = 0; i < paperCnt; i++)
	{
		int x, y;
		cin >> x >> y;

		for(int i = y; i < y+WIDTH; i++)
		{
			for(int j = x; j < x+WIDTH; j++)
			{
				if(!area[i][j])
				{
					area[i][j] = true;
					totalArea++;
				}
			}
		}
	}
	cout << totalArea;
	return 0;
}

/*
bool FirstNumCompare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

 
  	totalArea = paperCnt * 100;
	sort(papers.begin(), papers.end(), FirstNumCompare);

	for(int i = 1; i < paperCnt; i++)
	{
		int width = papers[i].first + WIDTH - papers[i - 1].first;
		if(width > 0)
		{
			int height = papers[i].second + WIDTH - papers[i - 1].second;
			if (height > 0 && height < 10)
			{
				totalArea -= (width * height);
				cout << "Width : " << width << ", Height : " << height << endl;
			}
			height = papers[i - 1].second + WIDTH - papers[i].second;
			if (height > 0 && height < 10)
			{
				totalArea -= (width * height);
				cout << "Width : " << width << ", Height : " << height << endl;
			}
		}
	}
 */