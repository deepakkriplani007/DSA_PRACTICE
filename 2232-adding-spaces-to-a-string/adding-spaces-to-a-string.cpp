class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int i=0;
        for(auto it:spaces){
            int len=it-i;
            string temp=s.substr(i,len);
            i=it;
            ans+=temp+" ";
        }
        ans+=s.substr(i);
        return ans;
    }
};