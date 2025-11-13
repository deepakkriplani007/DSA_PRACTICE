class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       int n=nums.size();
       vector<int>fbit(n,0);
       vector<int>setbitindex(32,-1);
       for(int i=n-1;i>=0;i--){
        int farthest=i;
        for(int j=0;j<32;j++){
            if((nums[i]>>j)&1){
                setbitindex[j]=i;
            }
            if(setbitindex[j]!=-1){
                farthest=max(farthest, setbitindex[j]);
            }
        }
        fbit[i]=farthest-i+1;
       }
       return fbit;
    }
};