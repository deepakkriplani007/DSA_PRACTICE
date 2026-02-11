class Solution {
public:
    bool check(vector<int>& nums) {
    //    int i=0;
    int c=0;
       for(int i=0;i<nums.size()-1;i++){
if(nums[i+1]<nums[i])c++;
    //    cout<<c<<i;
       } 
         if(nums[0]<nums.back()){
            c++;
        }
    if((c==1 )||c==0 ){return true;}else return false;
       
    }
};