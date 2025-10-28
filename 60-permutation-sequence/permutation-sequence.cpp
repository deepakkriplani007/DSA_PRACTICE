class Solution {
public:
    void nextper(string&s){
        int ind=-1;
        int n=s.size();
        for(int i=n-2;i>=0;i--){
            if(s[i+1]>s[i]){ind=i;break;}
        }
        if(ind==-1){
            reverse(s.begin(),s.end());
        }else{
            for(int i=n-1;i>ind;i--){
                if(s[i]>s[ind]){swap(s[i],s[ind]);break;}
            }
            reverse(s.begin()+ind+1,s.end());
        }
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        for(int i=1;i<k;i++){
            nextper(s);
        }
        return s;
    }
};