class Solution {
public:
    int makeres(int i, int j, vector<int>& nums,vector<vector<int>>&dp) {
        if (i > j)
            return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int cost = INT_MIN;
        for (int k = i; k <= j; k++) {
            // this kth ballon will burst at end
            int r=nums[k-1]*nums[k]*nums[k+1];
           int c=makeres(i,k-2,nums,dp)+makeres(k+2,j,nums,dp);
           cost=max(cost,c+r);
        }
        return dp[i][j]=cost;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        // return makeres(1, n, nums,dp);
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                 int cost = INT_MIN;
                for (int k = i; k <= j; k++) {
            int r=nums[i-1]*nums[k]*nums[j+1];
           int c=dp[i][k-1]+dp[k+1][j];
           cost=max(cost,c+r);
        }
         dp[i][j]=cost;
            }
        }
        // for( int i=0;i<n+2;i++){
        // for( int j=0;j<n+2;j++){
        // cout<<dp[i][j]<<" ";
        // }
        // cout<<endl;
        // }
        return dp[1][n];

    }
};