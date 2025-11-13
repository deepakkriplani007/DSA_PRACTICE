class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int r = 0;
        while ( r<nums.size()&& nums[r] < 0)
            r++;
        int l = -1;
        if (r != 0)
            l = r - 1;
        while (l >= 0 && r < nums.size()) {
            if (pow(nums[l], 2) < pow(nums[r], 2)) {
                ans.push_back(pow(nums[l], 2));
                l--;
            } else {
                ans.push_back(pow(nums[r], 2));
                r++;
            }
        }
        while (l >= 0) {
            ans.push_back(pow(nums[l], 2));
            l--;
        }
        while (r < nums.size()) {
            ans.push_back(pow(nums[r], 2));
            r++;
        }
        return ans;
    }
};