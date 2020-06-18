#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *currentNode = new ListNode(-1);
        currentNode->next = head;
        head = currentNode;
        while (currentNode->next != nullptr)
        {
            if (currentNode->next->val == val)
            {
                currentNode->next = currentNode->next->next;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
        return head->next;
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
    ListNode *dummyList = new ListNode();
    getList(dummyList);
    int val;
    cin >> val;
    Solution solver = Solution();
    ListNode *ret = solver.removeElements(dummyList->next, val);

    while (ret != nullptr)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
}