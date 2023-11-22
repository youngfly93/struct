






class Solution {
public:
    TreeNode* buildTree(vector <int> &preorder , vector <int> &inorder){
        if(preorder.size() == 0) return NULL;
        int pos = 0, n = preorder.size();
        while(inorder[pos] != preorder[0]) pos++;
        TreeNode* root = new TreeNode(preorder[0]);
        vector <int> preArr ,inArr;
        for(int i = 1 ;i < pos + 1;i++) preArr.push_back(preorder[i]);
        for(int i = 0 ;i < pos;i++) inArr.push_back(inorder[i]);
        root->left = buildTree(preArr,inArr);
        preArr.clear();
        inArr.clear();
        for(int i = pos +1  ; i < n ;i++) preArr.push_back(preorder[i]);
        for(int i = pos + 1 ; i < n ;i++) inArr.push_back(inorder[i]);
        root->right = buildTree(preArr,inArr);
        return root;
    }
};