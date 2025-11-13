class Solution {
public:
   bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    return false;
   }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int cv=0;
        while(j<k){
            if(isvowel(s[j]))cv++;
            j++;
        }
        int mv=cv;
        while(j<s.size()){
            if(isvowel(s[j]))cv++;
            j++;
            if(j-i+1>k){
                if(isvowel(s[i]))cv--;
                i++;
            }
            mv=max(mv,cv);
        }
        return mv;
    }
};