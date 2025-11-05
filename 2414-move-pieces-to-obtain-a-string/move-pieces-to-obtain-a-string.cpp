class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]!='_' && t[j]!='_' && (s[i]!=t[j]))return false;
            while(s[i]=='_' && i<s.size())i++;
            while(t[j]=='_' && j<t.size())j++;
            if(s[i]==t[j]){
               if(s[i]=='R' && i>j)return false;
               else if(s[i]=='L' && j>i)return false;
               else {
                i++;
                j++;
               }
         
            }
        }
        while(i<s.size()&& s[i]=='_')i++;
        while(j<t.size()&& t[j]=='_')j++;
        if((i<s.size() && s[i]!='_')||(j<t.size() && t[j]!='_'))return false;
        return true;
    }
};