class Solution {
public:
 int findPascalElement(int r, int c) {
        // Element is C(r-1, c-1)
        int n = r - 1;
        int k = c - 1;

        long long result = 1;

        // Compute C(n, k) using iterative formula
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }
    vector<vector<int>> generate(int nr) {
      vector<vector<int>>ans;
      for(int i=1;i<=nr;i++){
            vector<int>p;
        for(int j=1;j<=i;j++){
            p.push_back(findPascalElement(i,j));
        }
        ans.push_back(p);
      } 
      return ans;
    }
};