#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class ListNode1
{ // 单向链表
public:
    int val;
    ListNode1 *next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1 *next) : val(x), next(next) {}
};

class MyLinkedList
{ // 单向链表
    int size;
    ListNode1 *head;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        size = 0;
        head = new ListNode1(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        ListNode1 *curr = head;
        for (int i = 0; i < index + 1; ++i)
            curr = curr->next;
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index < 0)
            index = 0;
        ++size;
        ListNode1 *pred = head;
        for (int i = 0; i < index; ++i)
            pred = pred->next;

        ListNode1 *toAdd = new ListNode1(val, pred->next);
        pred->next = toAdd;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        size--;
        ListNode1 *pred = head;
        for (int i = 0; i < index; ++i)
            pred = pred->next;
        pred->next = pred->next->next;
    }
};

class ListNode2
{ // 双向链表
public:
    int val;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2() : val(0), next(nullptr), prev(nullptr) {}
    ListNode2(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode2(int x, ListNode2 *next, ListNode2 *prev) : val(x), next(next), prev(prev) {}
};

class MyLinkedList_2
{ // 双向链表
    int size;
    ListNode2 *head;
    ListNode2 *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList_2()
    {
        size = 0;
        head = new ListNode2(0);
        tail = new ListNode2(0);
        head->next = tail;
        tail->prev = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        ListNode2 *curr = head;
        if (index + 1 < size - index)
            for (int i = 0; i < index + 1; ++i)
                curr = curr->next;
        else
        {
            curr = tail;
            for (int i = 0; i < size - index; ++i)
                curr = curr->prev;
        }
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        ListNode2 *pred = head, *succ = head->next;

        ++size;
        ListNode2 *toAdd = new ListNode2(val);
        toAdd->prev = pred;
        toAdd->next = succ;
        pred->next = toAdd;
        succ->prev = toAdd;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        ListNode2 *succ = tail, *pred = tail->prev;

        ++size;
        ListNode2 *toAdd = new ListNode2(val);
        toAdd->prev = pred;
        toAdd->next = succ;
        pred->next = toAdd;
        succ->prev = toAdd;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        // If index is greater than the length,
        // the node will not be inserted.
        if (index > size)
            return;

        // [so weird] If index is negative,
        // the node will be inserted at the head of the list.
        if (index < 0)
            index = 0;

        // find predecessor and successor of the node to be added
        ListNode2 *pred, *succ;
        if (index < size - index)
        {
            pred = head;
            for (int i = 0; i < index; ++i)
                pred = pred->next;
            succ = pred->next;
        }
        else
        {
            succ = tail;
            for (int i = 0; i < size - index; ++i)
                succ = succ->prev;
            pred = succ->prev;
        }

        // insertion itself
        ++size;
        ListNode2 *toAdd = new ListNode2(val);
        toAdd->prev = pred;
        toAdd->next = succ;
        pred->next = toAdd;
        succ->prev = toAdd;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        // if the index is invalid, do nothing
        if (index < 0 || index >= size)
            return;

        // find predecessor and successor of the node to be deleted
        ListNode2 *pred, *succ;
        if (index < size - index)
        {
            pred = head;
            for (int i = 0; i < index; ++i)
                pred = pred->next;
            succ = pred->next->next;
        }
        else
        {
            succ = tail;
            for (int i = 0; i < size - index - 1; ++i)
                succ = succ->prev;
            pred = succ->prev->prev;
        }

        // delete pred.next
        --size;
        pred->next = succ;
        succ->prev = pred;
    }
};

vector<string> getOpt()
{
    vector<string> opt;
    string temp_opt;
    while (cin >> temp_opt)
    {
        opt.emplace_back(temp_opt);
        if (cin.get() == '\n')
            break;
    }
    return opt;
}

vector<vector<int>> getValue(int num)
{
    vector<vector<int>> value;
    value.resize(num);
    int i = 0;
    while (i < num)
    {
        vector<int> temp_val;
        int val;
        while (cin >> val)
        {
            temp_val.emplace_back(val);
            if (cin.get() == '\n')
                break;
        }
        value[i] = temp_val;
        ++i;
    }
    return value;
}

string makeOpt(string& opt, vector<int>& value, MyLinkedList* obj)
{
    if (opt == "get")
        return to_string(obj->get(value[0]));
    else if (opt == "addAtHead")
    {
        obj->addAtHead(value[0]);
        return "null";
    }
    else if (opt == "addAtTail")
    {
        obj->addAtTail(value[0]);
        return "null";
    }
    else if (opt == "addAtIndex")
    {
        obj->addAtIndex(value[0], value[1]);
        return "null";
    }
    else if (opt == "deleteAtIndex")
    {
        obj->deleteAtIndex(value[0]);
        return "null";
    }
    return "";
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    // 命令行输入输出还没搞定, 再议
    vector<string> opt({"MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"});
    vector<vector<int>> value({{}, {1}, {3}, {1,2}, {1}, {1}, {1}});
    
    MyLinkedList* obj = new MyLinkedList();
    string res = "[null,";
    for (int i = 1; i < opt.size(); ++i)
    {
        string temp = makeOpt(opt[i], value[i], obj);
        res += temp;
        if (i < opt.size() - 1)
            res += ',';
    }
    res += ']';

    cout << res << endl;

    return 0;
}