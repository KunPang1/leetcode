#include <iostream>
#include <deque>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int max_path;
    int maxPath(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_path = max(maxPath(root->left), 0);
        int right_path = max(maxPath(root->right), 0);
        max_path = max(max_path, left_path + right_path + root->val);
        return max(left_path, right_path) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        max_path = INT_MIN;
        maxPath(root);
        return max_path;
    }
};

TreeNode *creat_leave(TreeNode *root, bool is_left, string val)
{
    TreeNode *cur = new TreeNode(stoi(val));
    if (is_left){
        root->left = cur;
    }
    else
    {
        root->right = cur;
    }
    return cur;
}

TreeNode *get_binary_tree()
{
    string temp;
    deque<TreeNode*> dq;
    TreeNode* root = new TreeNode(0);
    while (cin >> temp)
    {
        if (temp == "null")
        {
            auto prev = dq.front();
            dq.pop_front();
            
            if (cin.get() == '\n')
                break;

            cin >> temp;
            if (temp != "null")
                dq.push_back(creat_leave(prev, false, temp));
        }
        else
        {
            int x = stoi(temp);
            TreeNode* cur = new TreeNode(x);
            if (dq.empty())
            {
                root = cur;
                dq.push_back(cur);
            }
            else 
            {
                auto prev = dq.front();
                dq.pop_front();
                prev->left = cur;
                dq.push_back(cur);

                if (cin.get() == '\n')
                    break;
                
                cin >> temp;
                if (temp != "null")
                    dq.push_back(creat_leave(prev, false, temp));
            }
        }
        if (cin.get() == '\n')
            break;
    }
    return root;
}

int main()
{
    auto root = get_binary_tree();
    Solution solver;
    auto x = solver.maxPathSum(root);
    cout << x << endl;
    return 0;
}