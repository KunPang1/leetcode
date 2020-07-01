#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

class Solution
{
private:
    /* data */
public:
    // 快排, 找第K个位置的数
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) return a[q];
        else return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }

    inline int randomPartition(vector<int>& a, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x)
                swap(a[++i], a[j]);
        }
        swap(a[i+1], a[r]);
        return i+1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    // 堆, 直接调用库函数
    int findKthLargest_1(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto it : nums) {
            q.push(it);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }

    // 建立一个大根堆
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1,  r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest])
            largest = 1;
        if (r < heapSize && a[r] > a[largest])
            largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapsize) {
        for (int i = heapsize / 2; i >= 0; --i)
            maxHeapify(a, i, heapsize);
    }

    int findKthLargest_2(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

int main()
{
    vector<int> nums;
    int k;
    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
        if (cin.get() == '\n') break;
    }
    cin >> k;
    Solution solver;
    auto x = solver.findKthLargest(nums, k);
    cout << x << endl;
    return 0;
}
