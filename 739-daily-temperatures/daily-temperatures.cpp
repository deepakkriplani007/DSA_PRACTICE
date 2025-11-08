class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        st.push(0);
        vector<int>ans(temp.size(),0);
        for (int i = 1; i < temp.size(); i++) {
            while (!st.empty() && temp[st.top()] < temp[i]) {
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};