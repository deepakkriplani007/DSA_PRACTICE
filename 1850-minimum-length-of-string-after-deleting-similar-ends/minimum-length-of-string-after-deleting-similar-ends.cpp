class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1)return 1;
        int i=0,j=s.size()-1;
        while(i<j){
          if(s[i]==s[j]){
            char c=s[i];
            while(s[i]==c && i<j)i++;
            while(s[j]==c && i<j)j--;
          }
          else{
            return j-i+1;
          }
        }
        return (s[i]==s[i-1]||s[i]==s[i+1])?0:1;
    }
};