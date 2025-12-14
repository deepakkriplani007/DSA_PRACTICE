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
       vector<vector<int>>adj(num);
       vector<int>in(num,0);
       for(auto it:pre){
        adj[it[1]].push_back(it[0]);
        in[it[0]]++;
       }
       queue<int>q;
       for(int i=0;i<num;i++){
        if(in[i]==0)q.push(i);
       }
       vector<int>ans;
       while(!q.empty()){
           auto f=q.front();
           q.pop();
           ans.push_back(f);
           for(auto it:adj[f]){
            in[it]--;
            if(in[it]==0)q.push(it);
           }
       }
       if(ans.size()==num)return ans;
       return {};

    }
};