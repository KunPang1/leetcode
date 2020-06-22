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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 通过vector构建二叉树
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

TreeNode *creat_leave(TreeNode *root, bool is_left, string val)
{
    TreeNode *cur = new TreeNode(stoi(val));
    if (is_left)
    {
        root->left = cur;
    }
    else
    {
        root->right = cur;
    }
    return cur;
}

// 通过键盘输入构建二叉树
TreeNode *get_binary_tree()
{
    string temp;
    deque<TreeNode *> dq;
    TreeNode *root = new TreeNode(0);
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
            TreeNode *cur = new TreeNode(x);
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

// 通过leetcode字符串转换为二叉树
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{                                     // 把字符串转换为树
    TreeNode *root = new TreeNode(0); // 创建根节点
    if (data.empty())
        return nullptr; // 传统艺能
    int j = 0;
    string sub = "";
    for (; data[j] >= '0' && data[j] <= '9' || data[j] == '-'; ++j)
    {
    } // 找到一个完整的数字在字符串的位置
    if (data[0] == '-')
    { // 处理负数情况
        sub = data.substr(1, j - 1);
        data.erase(0, j + 1);
        int number = stoi(sub);
        root->val = -number;
    }
    else
    {
        sub = data.substr(0, j);
        data.erase(0, j + 1);
        int number = stoi(sub);
        root->val = number;
    }
    queue<TreeNode *> q;
    q.push(root); //root处理完毕，压入队列
    int a = 1;
    while (!data.empty())
    { //开始处理左右节点
        cout << q.front()->val << endl;
        TreeNode *l = new TreeNode(0);
        TreeNode *r = new TreeNode(0);
        if (data[0] == 'n')
        { //左节点
            l = nullptr;
            data.erase(0, 5);
        }
        else if (!data.empty())
        {
            int i = 0;
            for (i; (data[i] >= '0' && data[i] <= '9') || data[i] == '-'; ++i)
            {
            }
            if (data[0] == '-')
            {
                sub = data.substr(1, i - 1);
                data.erase(0, i + 1);
                int num = stoi(sub);
                l->val = -num;
                q.push(l);
            }
            else
            {
                sub = data.substr(0, i);
                data.erase(0, i + 1);
                int num = stoi(sub);
                l->val = num;
                q.push(l);
            }
        }
        else
        {
            l = nullptr;
        }

        if (data[0] == 'n')
        { // 右节点
            r = nullptr;
            data.erase(0, 5);
        }
        else if (!data.empty())
        {
            int i = 0;
            for (i; (data[i] >= '0' && data[i] <= '9') || data[i] == '-'; ++i)
            {
            }
            if (data[0] == '-')
            {
                sub = data.substr(1, i - 1);
                data.erase(0, i + 1);
                int num = stoi(sub);
                r->val = -num;
                q.push(r);
            }
            else
            {
                sub = data.substr(0, i);
                data.erase(0, i + 1);
                int num = stoi(sub);
                r->val = num;
                q.push(r);
            }
        }
        else
        {
            r = nullptr;
        }

        TreeNode *n = q.front();
        n->left = l; //连接root 的 左右节点
        n->right = r;
        q.pop();
    }
    return root;
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{ //把树转化为字符串
    if (!root)
        return "[]";
    string ans = "[";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    { //遍历二叉树，BFS
        TreeNode *temp = q.front();
        q.pop();
        if (temp)
        {
            ans += to_string(temp->val);
            ans += ","; // 分割每个node
            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            ans += "null,"; // 即使是空节点也要转换成字符串，因为要将字符串还原为树，null作为占位符
        }
    }
    while (*(ans.end() - 2) == 'l')
    {
        ans.erase(ans.end() - 5, ans.end());
    }
    ans.pop_back();
    ans += ']';

    return ans;
}

int main()
{
    // 通过链表构建二叉树
    vector<int> s = {1, 4, 3, 2};
    TreeNode* root=getTreeNode(s);

    // 通过键盘输入构建二叉树
    TreeNode* root1 = get_binary_tree();

    // 通过leetcode字符串转换为二叉树
    string input = "[-10,9,20,null,null,15,7,3,null,null,15,62]";
    TreeNode *root2 = deserialize(input.substr(1, input.size() - 2));

    string output = serialize(root2);
    cout << output << endl;

    return 0;
}
