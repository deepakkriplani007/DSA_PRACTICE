class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.size(),mini=n,m=t.size(),d=0,len=n+m;
        unordered_map<char,int>mp;
        for(int k=0;k<m;k++){
            mp[t[k]]++;
        }
        while(j<n){
                    if(mp[s[j]]>0)d++;
                    mp[s[j]]--;
                    while(d==m ){
                        if(j-i+1<len){
                            len=j-i+1;
                            mini=i;
                        }
                        mp[s[i]]++;
                        if(mp[s[i]]>0)d--;
                        i++;
                    }
                   
            j++;
        }
        return s.substr(mini,len);
    }
};                     