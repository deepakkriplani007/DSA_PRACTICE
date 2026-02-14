class Solution {
public:
    int makeres(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int i=0,j=0,n=nums.size(),s=0,c=0;
        while(j<n){
            s+=nums[j];
            while(s>goal && i<=j){
                s-=nums[i];
                i++;
            }
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
          unordered_map<int,int>m;
        m[0]=1;
        int sum=0;
        int count=0;
        for(auto it:nums){
            sum+=it;
            if(m.find(sum-goal)!=m.end()){
                count+=m[sum-goal];
            }
            m[sum]++;
        }
        return count;
        
    }
};