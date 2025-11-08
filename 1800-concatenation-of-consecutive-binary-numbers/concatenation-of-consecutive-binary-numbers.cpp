#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        int bitshift = 0;

        for (int i = 1; i <= n; ++i) {
            // update number of bits for current i
            if ((i & (i - 1)) == 0) bitshift++;  // new power of two => increase bit length

            ans = ((ans << bitshift) % mod + i) % mod;
        }
        return (int)ans;
    }
};
