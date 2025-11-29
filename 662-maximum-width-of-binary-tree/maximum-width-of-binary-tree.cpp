/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int width=1;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second,min_ind,max_ind;
            int ind=0;
            for(int i=0;i<n;i++){
                pair<TreeNode *,int> p=q.front();
                q.pop();
                if(i==0)    min_ind=p.second;
                if(i==n-1)  max_ind=p.second;
                 ind=p.second-mini;
                cout<<p.first->val<<" "<<p.second<<endl;
                if(p.first->left)   q.push({p.first->left,(long long)2*ind+1});
                if(p.first->right)  q.push({p.first->right,(long long)2*ind+2});
            }
            width=max(width,ind+1);
        }
        return width;
    }
};
