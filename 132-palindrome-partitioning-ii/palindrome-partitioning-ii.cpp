class Solution {
public:
   int dp[2001];
   bool ispallin(string &s,int l,int r){
    //    int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int solve(string &s,int i,int j){
        if(i>=j || ispallin(s,i,j))return 0;
        if(dp[i]!=-1)return dp[i];
        // string temp="";
        int mncost=INT_MAX;
        for(int k=i;k<j;k++){
            // temp+=s[j];
            if(ispallin(s,i,k)){
              int  cost=1+solve(s,k+1,j);
                mncost=min(mncost,cost);
            }
        }
        return dp[i]= mncost;
    }
    int minCut(string s) {
       memset(dp,-1,sizeof(dp));
       return solve(s,0,s.size()-1);
    }
};