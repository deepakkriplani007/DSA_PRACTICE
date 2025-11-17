class Solution {
public:
    bool canConstruct(string rn, string mn) {
        vector<int>v(26,0);
        for(int i=0;i<mn.size();i++){
            v[mn[i]-'a']++;
        }
        for(int i=0;i<rn.size();i++){
            v[rn[i]-'a']--;
            if(v[rn[i]-'a']<0)return false;
        }
        return true;

    }
};