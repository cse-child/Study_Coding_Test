#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	set<int> angles;
	bool equal = true;
	int angleSum = 0;
	for (int i = 0; i < 3; i++)
	{
		int angle;
		cin >> angle;
		angles.insert(angle);
		angleSum += angle;
		if (angle != 60) equal = false;
	}

	if (equal)
		cout << "Equilateral" << endl;
	else
	{
		if (angleSum != 180)
			cout << "Error" << endl;
		else
		{
			if (angles.size() == 3)
				cout << "Scalene" << endl;
			else 
				cout << "Isosceles" << endl;
		}
	}
	
	return 0;
}