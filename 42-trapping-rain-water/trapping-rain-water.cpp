class Solution {
public:
    int trap(vector<int>& he) {
        int n=he.size();
        vector<int>premax(n);
        vector<int>postmax(n);
        premax[0]=he[0];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],he[i]);
        }
        postmax[n-1]=he[n-1];
        for(int i=n-2;i>=0;i--){
            postmax[i]=max(postmax[i+1],he[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=min(postmax[i],premax[i])-he[i];
        }
        return total;

    }
};