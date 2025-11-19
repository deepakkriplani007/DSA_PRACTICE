class Solution {
public:
    bool ispalindrom(string &s, int i, int e) {
        while (i <=e) {
            if (s[i++] != s[e--])
                return false;
        }
        return true;
    }
    void makeres(string &s, int ind, vector<vector<string>>& r,
                 vector<string> t) {
        if (ind == s.length()) {
            r.push_back(t);
            return;
        }
        for (int i = ind; i < s.size(); ++i) {
            if (ispalindrom(s, ind, i)) {
                t.push_back(s.substr(ind, i - ind + 1));
                makeres(s, i + 1, r, t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        vector<string> t;
        makeres(s, 0, r, t);
        return r;
    }
};