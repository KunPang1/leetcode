#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> BubbleSort(vector<int>& nums){
        int len = nums.size();
        for(int i = 0; i < len - 1; ++i){
            for(int j = 0; j < len - 1 - i; ++j){
                if(nums[j] > nums[j + 1]){
                    int temp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }
    vector<int> SelectionSort(vector<int>& nums){
        int len = nums.size();
        int minIndex, temp;
        for(int i = 0; i < len - 1; i ++){
            minIndex = i;
            for(int j = i + 1; j < len; ++j){
                minIndex = nums[j] < nums[minIndex] ? j : minIndex;
            }
            temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
        return nums;
    }
    vector<int> InsertionSort(vector<int>& nums){
        int len = nums.size();
        int preIndex, current;
        for(int i = 1; i < len; ++i){
            preIndex = i - 1;
            current = nums[i];
            while(preIndex >= 0 && nums[preIndex] > current){
                nums[preIndex + 1] = nums[preIndex];
                preIndex--;
            }
            nums[preIndex + 1] = current;
        }
        return nums;
    }
    vector<int> ShellSort(vector<int>& nums){
        int len = nums.size();
        for(int gap = (int)(len / 2); gap > 0; gap = (int)(gap / 2)){
            for(int i = gap; i < len; ++i){
                int j = i;
                int current = nums[i];
                while(j - gap >= 0 && current < nums[j - gap]){
                    nums[j] = nums[j - gap];
                    j = j - gap;
                }
                nums[j] = current;
            }
        }
        return nums;
    }
    // 归并排序
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) tmp[cnt++] = nums[i++];
        while (j <= r) tmp[cnt++] = nums[j++];
        for (int i = 0; i < r - l + 1; ++i) nums[i + l] = tmp[i];
    }
    vector<int> sortArray_merge(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    // 快速排序
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r){
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
    vector<int> sortArray_quick(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    // 堆排序
    void maxHeapify(vector<int>& nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            }
            else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            }
            else break;
        }
    }
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            maxHeapify(nums, i, len);
        }
    }
    void heapSort(vector<int>& nums) {
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);
        }
    }
    vector<int> sortArray_heap(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    // 计数排序
    vector<int> CountingSort(vector<int>& nums, int maxValue){
        vector<int> bucket(maxValue + 1, 0);
        int sorterIndex = 0, len = nums.size(), bucketLen = maxValue + 1;
        for(int i = 0; i < len; ++i){
            bucket[nums[i]]++;
        }
        for(int j = 0; j < bucketLen; ++j){
            while(bucket[j] > 0){
                nums[sorterIndex++] = j;
                bucket[j]--;
            }
        }
        return nums;
    }

    // 桶排序
    vector<int> BucketSort(vector<int>& nums, int bucketSize){
        if(nums.size() == 0) return nums;
        int i, minValue = nums[0], maxValue = nums[0];
        for(i = 1; i < nums.size(); ++i){
            if(nums[i] < minValue)
                minValue = nums[i];
            else if (nums[i] > maxValue)
                maxValue = nums[i];
        }
        // 桶的初始化，默认数量为5
        int DEFAULT_BUCKET_SIZE = 5;
        bucketSize = bucketSize || DEFAULT_BUCKET_SIZE;
        int bucketCount = (int)((maxValue - minValue) / bucketSize) + 1;
        vector<vector<int>> buckets(bucketCount);
        for(i = 0; i < nums.size(); ++i)
            buckets[(int)((nums[i] - minValue) / bucketSize)].push_back(nums[i]);
        vector<int> out;
        for(i = 0; i < buckets.size(); ++i){
            InsertionSort(buckets[i]); // 每个桶使用插入排序
            for(int j = 0; j < buckets[i].size(); ++j){
                out.push_back(buckets[i][j]);
            }
        }
        return out;
    }

    // 基数排序
    int maxbit(int data[], int n) //辅助函数，求数据的最大位数
    {
        int d = 1; //保存最大的位数
        int p = 10;
        for (int i = 0; i < n; ++i)
        {
            while (data[i] >= p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;
    }
    void radixsort(int data[], int n) //基数排序
    {
        int d = maxbit(data, n);
        int *tmp = new int[n];
        int *count = new int[10]; //计数器
        int i, j, k;
        int radix = 1;
        for (i = 1; i <= d; i++) //进行d次排序
        {
            for (j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器
            for (j = 0; j < n; j++)
            {
                k = (data[j] / radix) % 10; //统计每个桶中的记录数
                count[k]++;
            }
            for (j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
            for (j = n - 1; j >= 0; j--)            //将所有桶中记录依次收集到tmp中
            {
                k = (data[j] / radix) % 10;
                tmp[count[k] - 1] = data[j];
                count[k]--;
            }
            for (j = 0; j < n; j++) //将临时数组的内容复制到data中
                data[j] = tmp[j];
            radix = radix * 10;
        }
        delete[] tmp;
        delete[] count;
    }
};

int main(){
    vector<int> v1 = {5, 3, 5, 6, 4, 12, 343, 5, 3, 1, 3, 343, 4, 3, 5, 4, 6, 5, 34324, 2, 45, 2, 52, 6, 34, 6, 56, 3, 4, 32, 1, 5, 1, 3};
    Solution pro;
    auto x = pro.sortArray_heap(v1);
    for (auto temp : x)
        cout << temp << " ";
    cout << endl;
    return 0;
}