class Solution {
public:
   int setbit(int n){
    int cnt=0;
    while(n>0){
        n&=(n-1);
        cnt++;
    }
    return cnt;
   }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=setbit(i);
        }
        return ans;
    }
};