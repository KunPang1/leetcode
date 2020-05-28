#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getLinkNode(vector<int> str)
{
    ListNode *root = new ListNode(str[0]);
    vector<ListNode *> vecs;
    vecs.push_back(root);
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != NULL)
        {
            ListNode *n1 = new ListNode(str[i]);
            vecs[i - 1]->next = n1;
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

int main()
{
    int T;
    vector<int> s = {1, 2, 3, 4, 5};
    ListNode* root=getLinkNode(s);
    Solution pro;
    auto x = pro.reverseList(root);
    return 0;
}
