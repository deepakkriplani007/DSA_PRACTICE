class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            while((i>=0 && s[i]==' '))i--;
            string temp="";
            while(i>=0 && s[i]!=' '){
                temp+=s[i];
                i--;
            }
            reverse(temp.begin(),temp.end());
            if(temp!="")ans+=temp+" ";
        }
        return ans.substr(0,ans.size()-1);
    }
};