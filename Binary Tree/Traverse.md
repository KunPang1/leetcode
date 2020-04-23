# 三种遍历方式

> 参考 labuladong 大神 github <https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E5%AD%A6%E4%B9%A0%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%92%8C%E7%AE%97%E6%B3%95%E7%9A%84%E9%AB%98%E6%95%88%E6%96%B9%E6%B3%95.md>

## 二叉树节点

```c++
/* 基本的二叉树节点 */
struct BiTNode {
    int val;
    BiTNode *left, *right;
    BiTNode(int x) : val(x), left(NULL), right(NULL) {}
}BiTNode, *BiTree;

void traverse(BiTree root) {
    traverse(root->left)
    traverse(root->right)
}
```

## 遍历

```c++
void traverse(BiTree root) {
    // 前序遍历
    traverse(root->left)
    // 中序遍历
    traverse(root->right)
    // 后序遍历
}
```

LeetCode 124题， 二叉树中最大路径和

```c++
class Solution {
public:
    int ans;
    int oneSideMax(TreeNode* root){
        if(root == nullptr) return 0;
        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        oneSideMax(root);
        return ans;
    }
};
```

LeetCode 94题，直接用二叉树中序遍历即可，递归非递归都行

LeetCode 95题，不同的二叉搜索树II，后序遍历

```c++
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> all_trees;
        if(start > end){
            all_trees.push_back(NULL);
            return all_trees;
        }
        for(int i = start; i <= end; ++i){
            vector<TreeNode*> left_trees = helper(start, i - 1);
            vector<TreeNode*> right_trees = helper(i + 1, end);

            for(TreeNode* l : left_trees){
                for(TreeNode* r : right_trees){
                    TreeNode* current_tree = new TreeNode(i);
                    current_tree->left = l;
                    current_tree->right = r;
                    all_trees.push_back(current_tree);
                }
            }
        }
        return all_trees;
    }
```

Leetcode 199题，二叉树的右视图
前序遍历即可
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>& save, int& height){
        if(!root) return;
        if(height == save.size()) save.push_back(root->val); //如果当前深度没有点，则插入
        else save[height] = root->val;  // 如果当前深度有点，则更新
        height++;
        helper(root->left, save, height);
        helper(root->right, save, height);
        height--;
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> save;
        int height = 0;
        helper(root, save, height);
        return save;
    }
};
```

LeetCode 105题， 根据前序遍历和中序遍历还原二叉树

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    }
};
```

LeetCode 99题， 恢复二叉搜索树

```c++
class Solution {
public:
    void recoverTree(TreeNode* root) {
    }
};
```
