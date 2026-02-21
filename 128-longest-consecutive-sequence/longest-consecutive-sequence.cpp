class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty input
       sort(nums.begin(),nums.end());
        int f=0;
        int c=1;
        int last=nums[0];
        for(int i=1;i<nums.size();i++){
            if(last==nums[i]-1){
c++;
last=nums[i];
            }else if(last!=nums[i]){
                f=max(c,f);
                c=1;
                last=nums[i];
            }
        }
        f=max(c,f);
        return f;

    }
};