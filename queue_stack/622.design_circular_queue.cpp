#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue
{
    vector<int> que;
    int length;
    int count;
    int tail, head;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : length(k)
    {
        que.resize(k);
        count = 0;
        head = 0;
        tail = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (count == length)
            return false;
        que[tail] = value;
        tail++;
        if (tail == length)
            tail = 0;
        count++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (count == 0)
            return false;
        head++;
        if (head == length)
            head = 0;
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (count == 0) return -1;
        return que[head];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (count == 0) return -1;
        return tail == 0 ? que[length - 1] : que[tail - 1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        if (count == 0)
            return true;
        else
            return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        if (count == length)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int makeOpt(string &opt, vector<int> &value, MyCircularQueue *obj)
{
    if (opt == "enQueue")
        return obj->enQueue(value[0]);
    else if (opt == "deQueue")
        return obj->deQueue();
    else if (opt == "Front")
        return obj->Front();
    else if (opt == "Rear")
        return obj->Rear();
    else if (opt == "isEmpty")
        return obj->isEmpty();
    else if (opt == "isFull")
        return obj->isFull();
}

int main()
{
    // 命令行输入输出还没搞定, 再议
    vector<string> opt({"MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"});
    vector<vector<int>> value({{3}, {1}, {2}, {3}, {4}, {}, {}, {}, {4}, {}});

    int k = value[0][0];
    MyCircularQueue *obj = new MyCircularQueue(k);
    for (int i = 1; i < opt.size(); ++i)
    {
        int temp = makeOpt(opt[i], value[i], obj);
        cout << temp << endl;
    }

    return 0;
}