class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<r.size();i++){
            pq.push(c[i]-r[i]);
        }
        int ans=0;
        while(a>0 && !pq.empty()){
            int curr=pq.top();
            pq.pop();
            if(a>=curr){
                a-=curr;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};