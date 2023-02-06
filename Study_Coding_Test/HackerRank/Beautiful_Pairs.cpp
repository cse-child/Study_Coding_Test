#include "Framework.h"

int beautifulPairs(vector<int> A, vector<int> B) {
    int beautifulPairs = 0;

    for (int num : A)
    {
        int index = find(B.begin(), B.end(), num) - B.begin();
        if (index != B.size())
        {
            beautifulPairs++;
            B.erase(B.begin() + index);
        }
    }

    return beautifulPairs == A.size() ? beautifulPairs - 1 : beautifulPairs + 1;
}

int main()
{

}