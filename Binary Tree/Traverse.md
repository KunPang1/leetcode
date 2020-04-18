# 三种遍历方式

> 参考 labuladong 大神 github
 <https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E5%AD%A6%E4%B9%A0%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%92%8C%E7%AE%97%E6%B3%95%E7%9A%84%E9%AB%98%E6%95%88%E6%96%B9%E6%B3%95.md>

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
