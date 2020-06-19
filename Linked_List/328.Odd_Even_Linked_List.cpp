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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
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
    ListNode *dummyList = new ListNode();
    getList(dummyList);
    Solution solver = Solution();
    ListNode *ret = solver.oddEvenList(dummyList->next);

    while (ret != nullptr)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
}