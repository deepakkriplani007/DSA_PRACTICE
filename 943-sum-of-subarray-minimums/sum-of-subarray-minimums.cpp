class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>premin(n,-1);
        vector<int>postmin(n,n);
           int mod=1e9+7;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(!st.empty() && arr[st.top()]<=arr[i])premin[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(!st.empty() && arr[st.top()]<arr[i])postmin[i]=st.top();
            st.push(i);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            total+=1LL*((postmin[i]-i)*(i-premin[i]))*arr[i];
            total=total%mod;
        }
        return (int)total;

    }
};