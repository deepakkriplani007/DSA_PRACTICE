class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        int total=n*(n+1)/2;
        return total-s;
    }
};