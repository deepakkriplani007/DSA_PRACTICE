class Solution {
public:
   vector<int>arr;
    Solution(vector<int>& w) {
        for(auto it:w){
            if(arr.empty())arr.push_back(it);
            else arr.push_back(it+arr.back());
        }
    }
    
    int pickIndex() {
        int x=arr.back();
        int r=rand()%x;
         auto it = upper_bound(arr.begin(), arr.end(),r);
         return it-arr.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */