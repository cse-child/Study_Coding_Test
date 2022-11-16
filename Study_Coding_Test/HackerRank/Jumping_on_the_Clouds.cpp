#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c) {
    int jumpCount = 0;
    int idx = 0;
    while (idx < c.size() - 1)
    {
        if (c[idx + 2] == 0)
            idx += 2;
        else if (c[idx + 1] == 0)
            idx += 1;

        jumpCount++;
    }
    return jumpCount;
}