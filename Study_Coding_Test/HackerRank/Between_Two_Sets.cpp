#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    int count = 0;

    int maxA = *max_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());

    for (int i = maxA; i <= minB; i++)
    {
        bool isDivide = true;
        for (int aNum : a)
        {
            if (i % aNum != 0)
                isDivide = false;
        }
        for (int bNum : b)
        {
            if (bNum % i != 0)
                isDivide = false;
        }
        if (isDivide)
            count++;
    }
    return count;
}
