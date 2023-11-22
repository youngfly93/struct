/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution{
public:
    void __preorder(Node* root,vector <int> &ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        for(auto x:root->children){
            __preorder(x,ans)
        }
        return;
    }

    vector <int> preorder(Node* root){
        vector <int> ans;
        __preorder(root,ans);
        return ans;
    }
};

class Solution{
public:
    vector <int> preorder(Node* root){
        if(root == NULL) return vector <int> ();
        vector <int> ans;
        ans.push_back(root->val);
        for(auto x : root->children ){
            vector <int> temp =  preorder(x);
            for(auto y: temp)  ans.push_back(y);
        }
    }
    return ans;
};