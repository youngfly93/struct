class Solution {
public:
    vector <vector<int>> levelOrder(TreeNode* root){
        if(root == NULL)  return vector <vector<int>> ();
        TreeNode* node;
        queue <TreeNode*> q;
        q.push(root);
        vector <vector<int>> ans;
        while(!q.empty()){
            int cnt = q.size();
            vector<int> temp;
            for(int i = 0;i < cnt;i++){
                node = q.front();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


class Solution{
public:
    void dfs(TreeNode* root,int k ,vector<vector<int>> &ans){
        if (root==NULL) return;
        if(k == ans.size())   ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left,k+1,ans);
        dfs(root->right,k+1,ans);
        return;
    }
    vector <vector<int>> levelOrder(TreeNode* root){
       vector<vector<int>> ans;
       dfs(root,0,ans);
       return ans; 
    }
};