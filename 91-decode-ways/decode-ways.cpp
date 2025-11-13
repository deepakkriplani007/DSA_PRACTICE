class Solution {
public:
    int makeres(string& s, int i, vector<int>& dp) {
        if (i == s.size() - 1 )
        {
            if(s[i]=='0')return 0;
            return 1;
        }
        if(i>=s.size())return 1;
        int ans = 0;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];
        else if (s[i] == '1') {
            if (i + 1 < s.size() && s[i + 1] == '0') {
                ans = makeres(s, i + 2, dp);
            } else {
                ans = makeres(s, i + 1, dp) + makeres(s, i + 2, dp);
            }
        } else if (s[i] == '2') {
            if (i + 1 < s.size() && s[i + 1] == '0') {
                ans = makeres(s, i + 2, dp);
            } else if (i + 1 < s.size() && s[i + 1] <= '6' && s[i + 1] >= '1') {
                ans = makeres(s, i + 1, dp) + makeres(s, i + 2, dp);
            } else {
                ans = makeres(s, i + 1, dp);
            }
        } else {
            ans = makeres(s, i + 1, dp);
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) { 
        if (s[0] == '0') return 0;
        vector<int> dp(s.size(), -1);
        return makeres(s, 0, dp); 
    }
};
