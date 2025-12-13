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

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        // return makeres(s,t,s.size()-1,t.size()-1,dp);
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;


        for (int i = 1; i <= n; i++) {
            for (int j =1;j<=m;j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }
        return dp[n][m];
    }
};