class Solution {
public:
    // check dag then toposort
    // check dag m modification
    bool dfs(vector<int>& v, vector<vector<int>>& graph, int node,
             vector<int>& ans,vector<int>& pv) {
        v[node] = 1;
        pv[node]=1;
        for (auto it : graph[node]) {
            if (v[it] == 0) {
                if (dfs(v, graph, it, ans,pv))
                    return true;
            } else if (pv[it] == 1)
                return true;
        }
        ans.push_back(node);
        pv[node]=0;
        return false;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> graph(num);
        for (auto it : pre) {
            graph[it[1]].push_back(it[0]);
        }
        vector<int> v(num, 0);
        vector<int> pv(num, 0);
        vector<int> ans;
        for (int i = 0; i < num; i++) {
            if (v[i] == 0) {
                if (dfs(v, graph, i, ans,pv))
                    return {};
            } 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};