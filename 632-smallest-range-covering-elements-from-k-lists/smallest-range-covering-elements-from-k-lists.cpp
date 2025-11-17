class Solution {
public:
    bool isallset(vector<int>& v) {
        return find(v.begin(), v.end(), 0) == v.end();  // all lists covered
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            for (int x : nums[i]) v.push_back({x, i});
        }

        sort(v.begin(), v.end());

        vector<int> allind(nums.size(), 0);
        int i = 0, j = 0;

        int best = INT_MAX;
        int L = -1, R = -1;

        while (j < v.size()) {
            allind[v[j].second]++;   // expand window
            j++;

            while (isallset(allind)) {  // fully covered
                int range = v[j-1].first - v[i].first;

                if (range < best) {
                    best = range;
                    L = v[i].first;
                    R = v[j-1].first;
                }

                allind[v[i].second]--;  // shrink
                i++;
            }
        }

        return {L, R};
    }
};
