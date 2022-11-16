#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
    int pairCount = 0;
    map<int, int> socks;

    for (int num : ar)
        socks[num]++;

    for (pair<int, int> sock : socks)
        pairCount += (sock.second / 2);

    return pairCount;
}