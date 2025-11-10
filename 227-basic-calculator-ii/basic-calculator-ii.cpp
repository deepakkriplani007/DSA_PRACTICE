class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        char sign = '+';
        long n = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            char it = s[i];
            if (isdigit(it))
                n = n * 10 + (it - '0');

            // process when operator or end of string
            if ((!isdigit(it) && !isspace(it)) || i == len - 1) {
                if (sign == '+')
                    st.push(n);
                else if (sign == '-')
                    st.push(-n);
                else if (sign == '*') {
                    long top = st.top();
                    st.pop();
                    st.push(top * n);
                }
                else if (sign == '/') {
                    long top = st.top();
                    st.pop();
                    st.push(top / n);
                }
                sign = it;
                n = 0;
            }
        }

        long res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return (int)res;
    }
};
