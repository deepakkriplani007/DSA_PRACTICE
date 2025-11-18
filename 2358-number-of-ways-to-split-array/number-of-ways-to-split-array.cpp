class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> tillsum(n);

        tillsum[0] = nums[0];
        for (int i = 1; i < n; i++)
            tillsum[i] = tillsum[i - 1] + nums[i];

        long long total = tillsum.back();
        int c = 0;

        for (int i = 0; i < n - 1; i++) {
            long long left = tillsum[i];
            long long right = total - left;
            if (left >= right)
                c++;
        }
        return c;
    }
};
