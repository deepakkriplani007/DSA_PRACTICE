class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxA = 0;

        for (int i = 0; i < n; i++) {
            
            // Build heights
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            // Reset leftmin and rightmin for EACH ROW
            vector<int> leftmin(m, -1);
            vector<int> rightmin(m, m);

            stack<int> st;

            // Compute leftmin
            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] >=height[j])
                    st.pop();
                if (!st.empty())
                    leftmin[j] = st.top();
                st.push(j);
            }

            // Clear stack for rightmin
            while (!st.empty()) st.pop();

            // Compute rightmin
            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();
                if (!st.empty())
                    rightmin[j] = st.top();
                st.push(j);
            }

            // Compute max area for this row
            for (int j = 0; j < m; j++) {
                maxA = max(maxA, (rightmin[j] - leftmin[j] -1) * height[j]);
            }
        }

        return maxA;
    }
};
