class Solution {
public:
    string solve(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string n = "";
        while (!st.empty()) {
            n += st.top();
            st.pop();
        }
        reverse(n.begin(), n.end());
        return n;
    }
    bool backspaceCompare(string s, string t) {
        if (solve(s) == solve(t))
            return true;
        return false;
    }
};