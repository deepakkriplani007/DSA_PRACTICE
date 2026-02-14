class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        vector<int>leftsum(k+1,0);
        vector<int>rightsum(k+1,0);
        for(int i=1;i<=k;i++){
            leftsum[i]=cp[i-1]+leftsum[i-1];
        }
        int n=cp.size();
        for(int i=1;i<=k;i++){
            rightsum[i]=cp[n-i]+rightsum[i-1];
        }
       
        int i=0,j=k;
        int ans=INT_MIN;
        while(i<=k){
            ans=max(ans,leftsum[i]+rightsum[k-i]);
            i++;
        }
        return ans;

    }
};