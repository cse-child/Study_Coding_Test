#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    for (int i = 1; i <= 10000; i++)
    {
        if (x1 + v1 * i == x2 + v2 * i)
            return "YES";
    }
    return "NO";
}

int main()
{
    kangaroo(0, 3, 4, 2);
}