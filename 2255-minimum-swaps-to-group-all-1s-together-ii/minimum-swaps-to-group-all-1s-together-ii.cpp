class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int no=accumulate(nums.begin(),nums.end(),0);
        int cwo=accumulate(nums.begin(),nums.begin()+no,0);
        int ans=no-cwo;
        for(int i=0;i<n;i++){
            cwo-=nums[i];
            cwo+=nums[(i+no)%n];
            ans=min(ans,no-cwo);
        }
        return ans;
    }
};