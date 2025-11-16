class Solution {
public:
    bool isallset(vector<int>& v) {
        // Check if all elements are 1
        return find(v.begin(), v.end(), 0) == v.end();
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;

        // Merge all values with (value, listIndex)
        for (int i = 0; i < nums.size(); i++) {
            for (auto it : nums[i]) {
                v.push_back({it, i});
            }
        }

        sort(v.begin(), v.end());

        int n = nums.size();
        vector<int> count(n, 0);
        int covered = 0;

        int i = 0;
        int bestL = 0, bestR = INT_MAX;

        for (int j = 0; j < v.size(); j++) {
            int idx = v[j].second;

            if (count[idx] == 0) covered++;
            count[idx]++;

            // Try to shrink the window when all lists are covered
            while (covered == n) {
                int L = v[i].first;
                int R = v[j].first;

                if (R - L < bestR - bestL) {
                    bestL = L;
                    bestR = R;
                }

                // Shrink from left
                int leftIdx = v[i].second;
                count[leftIdx]--;
                if (count[leftIdx] == 0) covered--;

                i++;
            }
        }

        return {bestL, bestR};
    }
};
