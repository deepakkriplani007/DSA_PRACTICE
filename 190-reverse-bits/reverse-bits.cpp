class Solution {
public:
    int reverseBits(int n) {
        int pw=31;
        int ans=0;
        while(n){
            int cbit=n&(1);
            ans+=cbit*pow(2,pw);
           
            pw--;
            n=n>>1;
        }
        return ans;
    }
};