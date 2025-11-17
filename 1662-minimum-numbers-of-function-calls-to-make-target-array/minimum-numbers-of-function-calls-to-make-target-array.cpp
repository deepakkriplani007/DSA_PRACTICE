class Solution {
public:
    bool isallnotzero(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                return true;
        }
        return false;
    }
    int minOperations(vector<int>& nums) {
        int c = 0,n = nums.size();
        while (isallnotzero(nums)) {
            for (int i = 0; i < n; i++) {
                if (nums[i] & 1) {
                    c++;
                    nums[i]--;
                }
            }
            if(isallnotzero(nums)){
            c++;
            for (int i = 0; i < n; i++) {
                nums[i] /= 2;
            }
            }
        }
        return c;
    }
};