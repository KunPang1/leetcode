#include <iostream>
#include <queue>

using namespace std;

/* Function: 构建大顶堆 */
void BuildMaxHeap(int *heap, int len)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    int temp;
    for (i = len / 2 - 1; i >= 0; --i)
    {
        if ((2 * i + 1) < len && heap[i] < heap[2 * i + 1]) //根节点小于左子树
        {
            temp = heap[i];
            heap[i] = heap[2 * i + 1];
            heap[2 * i + 1] = temp;
            // 检查交换后的左子树是否满足大顶堆性质， 如果不满足 则重新调整子树结构
            if ((2 * (2 * i + 1) + 1 < len && heap[2 * i + 1] < heap[2 * (2 * i + 1) + 1]) || (2 * (2 * i + 1) + 2 < len && heap[2 * i + 1] < heap[2 * (2 * i + 1) + 2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
        if ((2 * i + 2) < len && heap[i] < heap[2 * i + 2]) //根节点小于右子树
        {
            temp = heap[i];
            heap[i] = heap[2 * i + 2];
            heap[2 * i + 2] = temp;
            // 检查交换后的右子树是否满足大顶堆性质， 如果不满足 则重新调整子树结构
            if ((2 * (2 * i + 2) + 1 < len && heap[2 * i + 2] < heap[2 * (2 * i + 2) + 1]) || (2 * (2 * i + 2) + 2 < len && heap[2 * i + 2] < heap[2 * (2 * i + 2) + 2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
    }
}