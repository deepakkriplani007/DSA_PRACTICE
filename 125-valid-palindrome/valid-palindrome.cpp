class Solution {
public:
    bool alphabet(char c){
        if(c<='Z'&& c>='A')return true;
        if(c<='z'&& c>='a')return true;
        if(c<='9'&& c>='0')return true;

        return false;
    }
    bool alphanumeric(char c){
        return false;
        }
    bool isPalindrome(string s) {
        string sn="";
        for(int i=0;i<s.size();i++){
            if(alphabet(s[i])){
                sn+=tolower(s[i]);
            }
            
        }
        cout<<sn<<endl;
        int i=0,j=sn.size()-1;
        while(i<j){
            if(sn[i]==sn[j]){
                i++;j--;
            }else{
                return false;
            }
        }
        return true;
    }
};