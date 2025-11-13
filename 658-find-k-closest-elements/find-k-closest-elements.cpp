class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i,j;
        vector<int>ans;
        if(ind<arr.size() && arr[ind]==x){
            ans.push_back(x);
            i=ind-1;
            j=ind+1;
        }else{
            i=ind-1;
            j=ind;
        }

        while(i>=0 && j<arr.size() && ans.size()<k){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
            }else{
                ans.push_back(arr[j]);
                j++;
            }
        }
        while(i>=0 && ans.size()<k){
            ans.push_back(arr[i]);
                i--;
        }
        while(j<arr.size() && ans.size()<k){
                ans.push_back(arr[j]);
                j++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};