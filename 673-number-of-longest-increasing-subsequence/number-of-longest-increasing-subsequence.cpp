class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);//this tell us what is longest length of subsequence till i
        vector<int>cdp(n,1);//this tell us how many of that length

        int ans=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //if we get a number at index j<i and nums[i]>nums[j] then two condition occur
                // first longest length till i is less then longest length j +1(why plus 1 because we get a next memmber in sequence of increasing which is i and not count in dp[j] )
                // if it is then change dp[i] cdp[i]
                //second if dp[i]==dp[j]+1 means(there are now two sequence of same length) so add in cdp[i] 
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;

                    cdp[i]=cdp[j];
                   }else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                    cdp[i]+=cdp[j];
                    // cout<<"ys";
                   }
                }
                ans=max(ans,dp[i]);
            }

            int c=0;
            // for(int i=0;i<n;i++){
            //  cout<<dp[i]<<" ";
            // }
            // cout<<endl;
            // for(int i=0;i<n;i++){
            //  cout<<cdp[i]<<" ";
            // }
            // cout<<endl;
            for(int i=0;i<n;i++){
                if(dp[i]==ans){
                    c+=cdp[i];

                }
            }
            return c;
        }
    
};