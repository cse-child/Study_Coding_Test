#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

long repeatedString(string s, long n) {
    long aCount = 0;
    long sInACount = 0;

    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            sInACount++;
    }

    aCount = (n / s.size()) * sInACount;

    for (long i = 0; i < (n % s.size()); i++)
    {
        if (s[i] == 'a')
            aCount++;
    }

    return aCount;
}