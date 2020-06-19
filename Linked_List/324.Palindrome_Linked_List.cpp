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
    // solution 1
private:
    ListNode *frontPointer;
    bool recursivelyCheck(ListNode *currentNode)
    {
        if (currentNode != nullptr)
        {
            if (!recursivelyCheck(currentNode->next))
                return false;
            if (currentNode->val != frontPointer->val)
                return false;
            frontPointer = frontPointer->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};

class Solution2
{
    // solution2
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    ListNode *endOfFirstHalf(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr) return true;
        // Find end of fist half and reverse second half.
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        // Check whether or not there is a palindrome;
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }        

        // Restore the list and return the result.
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
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
    Solution2 solver = Solution2();
    bool ret = solver.isPalindrome(dummyList->next);

    cout << ret << endl;
}