class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       int left=0,n=arr.size();
       for(;left<n-1;left++){
        if(arr[left]>arr[left+1])break;
       }
       if(left==n-1)return 0;
       int right=n-1;
       while(right>left &&arr[right-1]<=arr[right] )right--;
       int ans=min(n-left-1,right),i=0,j=right;
       while(i<=left && j<n){
        if(arr[j]>=arr[i]){
            ans=min(ans,j-i-1);
            i++;
        }else{
            j++;
        }
       }
       return ans;
    }
};