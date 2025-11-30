class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> st;
        st.push({sr, sc});
        int star=grid[sr][sc];
        int k=0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!st.empty() ) {
            
            pair<int, int> f = st.front();
            st.pop();
            int i = f.first;
            int j = f.second;
            
            grid[i][j]=color;

            for (auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < grid.size() && nj >= 0 &&
                    nj < grid[ni].size() && grid[ni][nj] == star &&grid[ni][nj] != color) {
                    st.push({ni, nj});
                }
            }
        
        }
        return grid;
    }
};