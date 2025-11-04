class Solution {
public:
    int makeres(vector<vector<int>>& books, int i, int cw, int ch, int sw, vector<vector<int>>& dp) {
        if (i >= books.size()) return ch;

        if (dp[i][cw] != -1) return dp[i][cw];

        int t = INT_MAX;

        // Option 1: Place the current book on the same shelf if it fits
        if (cw + books[i][0] <= sw) {
            t = makeres(books, i + 1, cw + books[i][0], max(ch, books[i][1]), sw, dp);
        }

        // Option 2: Start a new shelf
        int nt = ch + makeres(books, i + 1, books[i][0], books[i][1], sw, dp);

        return dp[i][cw] = min(t, nt);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i][cw] = minimum total height from book i onwards, given cw width used in current shelf
        vector<vector<int>> dp(books.size() + 1, vector<int>(shelfWidth + 1, -1));
        return makeres(books, 0, 0, 0, shelfWidth, dp);
    }
};
