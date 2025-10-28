class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        if (n == 0)
            return v;
        v.push_back(0);
        v.push_back(1);

        int i = 1;
        while (i < n) {
            int pow = 1 << i;
            int li = v.size()-1;
            while (li >= 0) {
                v.push_back(pow^v[li]);
                li--;
            }
            i++;
        }
        return v;
    }
};