#include <iostream>
#include <string>

using namespace std;

int countingValleys(int steps, string path) {
    int valley = 0;
    int curStep = 0;
    const int valleyRange = 0;

    for (int i = 0; i < steps; i++)
    {
        if (path[i] == 'U')
            curStep++;
        else
            curStep--;

        if (path[i] == 'U' && curStep == 0)
            valley++;
    }
    return valley;
}