class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < mat.size(); i++) {
            int co = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1)
                    co++;
            }
            if (pq.size() > k) {
                if (pq.top().first > co) {
                    pq.pop();
                    pq.push({co, i});
                }
            } else {
                pq.push({co, i});
            }
        }

        while (pq.size() > k) {
            pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};