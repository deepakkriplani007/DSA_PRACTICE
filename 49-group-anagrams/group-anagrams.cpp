class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>dp;
        for(auto str:strs){
            vector<int>fre(26,0);
            for(auto it:str){
                fre[it-'a']++;
            }
            string x="";
            for(auto it:fre){
                x+=to_string(it)+"*";
            }
            dp[x].push_back(str);
        }
            vector<vector<string>>ans;
            for(auto it:dp){
                ans.push_back(it.second);
            }
            return ans;

    }
};