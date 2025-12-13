class Solution {
public:
 const int MOD = 1e9 + 7;
    int makeres(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int r = 0;

        if (s[i] == t[j]) {
            r = makeres(s, t, i - 1, j - 1, dp) + makeres(s, t, i - 1, j, dp);
        } else {
            r = makeres(s, t, i - 1, j, dp);
        }

        return dp[i][j] = r;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return makeres(s,t,s.size()-1,t.size()-1,dp);
     
    
    }
};