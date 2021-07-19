#include <iostream>
#include <vector>
#include <map>
using namespace std;
//Definition for binary tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    void inorder(TreeNode*root, vector<int> & vec)
    {
        if(root==nullptr) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right,vec);

    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        //preorder:  curnode-> left(till the end)-> right(till the end)
        //inorder: left(till the end)->curnode->right(till the end)
        //postorder: right(till the end)->curnode->right(till the end
        //to do it recursively, create another fucntion.
        vector<int> ans={};
        inorder(root, ans);
        return ans;
    }
};
int main(void)
{
    TreeNode* root=new TreeNode(1);
    TreeNode * temp=root;
    temp->right=new TreeNode(2);
    temp=temp->right;
    temp->left=new TreeNode(3);
    Solution s;
    vector<int> vec;
    vec=s.inorderTraversal(root);
    cout<<"[ ";
    if(vec.empty()) cout<<" ";
    for( auto & element: vec)
    {
        cout<<element<<" ";
    }
    cout<<"]"<<"\n";

    return 0;
}