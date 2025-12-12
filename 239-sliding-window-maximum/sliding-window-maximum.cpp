class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k;i++){
            while(!dq.empty()&& dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        if(nums[0]==dq.front())dq.pop_front();
        int i=1,j=k;
        while(j<nums.size()){
            while(!dq.empty()&& dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            ans.push_back(dq.front());
            if(nums[i]==dq.front())dq.pop_front();
            i++;j++;
        }
        return ans;
    }
};