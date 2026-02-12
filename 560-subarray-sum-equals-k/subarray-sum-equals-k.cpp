class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int c=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
sum=sum+nums[i];
int r=sum-k;
c=c+mp[r];
mp[sum]=mp[sum]+1;
        }
        return c;
    }
};