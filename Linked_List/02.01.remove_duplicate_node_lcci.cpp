#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 我的解法--哈希表
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) return head;
        unordered_set<int> memo;
        ListNode *root = new ListNode(-1);
        root->next = head;
        auto cur = root;
        while (cur && cur->next) {
            while (cur->next && memo.count(cur->next->val)) {
                cur->next = cur->next->next;
            }
            if (!cur->next) break;
            memo.insert(cur->next->val);
            cur = cur->next;
        }
        return root->next;
    }

    // 官方题解--哈希表
    ListNode* removeDuplicateNodes1(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            ListNode* cur = pos->next;
            if (!occurred.count(cur->val)) {
                occurred.insert(cur->val);
                pos = pos->next;
            } else {
                pos->next = pos->next->next;
            }
        }
        pos->next = nullptr;
        return head;
    }

    // 两重循环，不用哈希表， 时间复杂度为 O(N^2)
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* ob = head;
        while (ob != nullptr) {
            ListNode* oc = ob;
            while (oc->next != nullptr) {
                if (oc->next->val == ob->val) {
                    oc->next = oc->next->next;
                } else {
                    oc = oc->next;
                }
            }
            ob = ob->next;
        }
        return head;
    }
};

void getList(ListNode *l)
{
    int a;
    while (cin >> a)
    {
        l->next = new ListNode(a);
        l = l->next;
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

int main()
{
    ListNode *dummyList = new ListNode(-1);
    getList(dummyList);
    Solution solver = Solution();
    ListNode *ret = solver.removeDuplicateNodes(dummyList->next);

    while (ret != nullptr)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
}