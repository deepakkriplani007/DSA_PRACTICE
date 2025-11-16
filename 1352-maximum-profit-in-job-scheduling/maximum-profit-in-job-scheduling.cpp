class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pro) {
        int n=st.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({st[i],et[i],pro[i]});
        }
        sort(v.begin(),v.end());
        vector<int>dp(n,0);
        vector<int>sttime(n,0);
        for(int i=0;i<n;i++){
            sttime[i]=v[i][0];
        }
        dp[n-1]=v[n-1][2];
        for(int i=n-2;i>=0;i--){
            int start=v[i][0];
            int endt=v[i][1];
            int profit=v[i][2];
            int next=lower_bound(sttime.begin(),sttime.end(),endt)-sttime.begin();
            cout<<next<<endl;
            if(next<sttime.size()){
            profit+=dp[next];
            }
            dp[i]=max(dp[i+1],profit);
        }
        return dp[0];
        
    }
};