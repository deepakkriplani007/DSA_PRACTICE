class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        vector<long long> ans(n+1, 0);
        long long sum = diff[0];

        for (int i = 1; i < n+1; i++) {
            ans[i] = ans[0] + sum;
           if(i!=n) sum += diff[i];
            // cout<<sum<<" ";
        }
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        long long lo = *min_element(ans.begin(), ans.end());
        long long up = *max_element(ans.begin(), ans.end());
        // cout<<lo<<" "<<up<<endl;

        long long range = (upper - lower) - (up - lo) + 1;
        return max(0LL, range);
    }
};
