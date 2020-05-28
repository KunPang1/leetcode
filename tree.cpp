#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getTreeNode(vector<int> str)
{
    TreeNode *root = new TreeNode(str[0]);
    vector<TreeNode *> vecs;
    vecs.push_back(root);
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != NULL)
        {
            TreeNode *n1 = new TreeNode(str[i]);
            if (i % 2 == 1) //left
            {
                vecs[(i - 1) / 2]->left = n1;
            }
            else
            {
                vecs[(i - 1) / 2]->right = n1;
            }
            vecs.push_back(n1);
        }
        else
        {
            vecs.push_back(nullptr);
        }
    }
    return root;
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> save;
        unordered_set<TreeNode*> memo;
        vector<int> out;
        if(root == NULL) return out;
        out.push_back(root->val);
        save.push(root);
        while(!save.empty()){
            if(memo.count(save.top()->left) == 0 && save.top()->left != NULL){
                out.push_back(save.top()->left->val);
                save.push(save.top()->left);
            }
            else if(memo.count(save.top()->right) == 0 && save.top()->right != NULL){
                out.push_back(save.top()->right->val);
                save.push(save.top()->right);
            }
            else{
                memo.insert(save.top());
                save.pop();
            }
        }
        return out;
    }
};

int main()
{
    int T;
    vector<int> s = {1, 4, 3, 2};
    TreeNode* root=getTreeNode(s);
    Solution pro;
    auto x = pro.preorderTraversal(root);
    return 0;
}
