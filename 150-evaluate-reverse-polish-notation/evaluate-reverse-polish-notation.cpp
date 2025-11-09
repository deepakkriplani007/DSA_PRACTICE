class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if (t == "+") st.push(b + a);
                else if (t == "-") st.push(b - a);
                else if (t == "*") st.push(b * a);
                else st.push(b / a);
            }
        }
        return st.top();
    }
};
