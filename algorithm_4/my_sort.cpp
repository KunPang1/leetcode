#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Example_sort{
public:
    void select_sort(vector<T>& a);
    void insert_sort(vector<T>& a);
    void shell_sort(vector<T>& a);
    bool less(T v, T w) { return v <= w; }
    void exch(vector<T>& a, int i, int j)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    void show(vector<T>& a) {
        // 单行中打印数组
        for (int i = 0; i < a.size(); ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    bool isSorted(vector<T>& a){
        // 测试数组是否有序
        for (int i = 1; i < a.size(); ++i)
            if (less(a[i], a[i] - 1)) return false;
        return true;
    }
};

// 选择排序
/*
* 一种最简单的排序算法是这样的:首先,找到数组中最小的那个元素,其次,将它和数组的第一个
* 元素交换位置(如果第一个元素就是最小元素那么它就和自己交换)。再次,在剩下的元素中
* 找到最小的元素,将它与数组的第二个元素交换位置。如此往复,直到将整个数组排序。这种方法
* 叫做选择排序,因为它在不断地选择剩余元素之中的最小者。
* 对于长度为N的数组,选择排序需要大约 N^2 / 2 次比较和 N 次交换。
*/
template <class T>
void Example_sort<T>::select_sort(vector<T>& a)
{
    int N = a.size();
    for (int i = 0; i < N; ++i) {
        int min_index = i;
        for (int j = i + 1; j < N; ++j)
            if (less(a[j], a[min_index])) min_index = j;
        exch(a, i, min_index);
    }
}

// 插入排序
/*
* 命题B。对于随机排列的长度为N且主键不重复的数组,平均情况下插入排序需要~N^2/4次比
* 较以及~N^2/4次交换。最坏情况下需要~N^2/2次比较和~N^2/2次交换,最好情况下需要N-1
* 次比较和0次交换。
*/
template <class T>
void Example_sort<T>::insert_sort(vector<T>& a)
{
    int N = a.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i; j > 0 && less(a[j], a[j-1]); --j)
            exch(a, j, j - 1);
    }
}

// 希尔排序
template <class T>
void Example_sort<T>::shell_sort(vector<T>& a)
{
    int N = a.size();
    int h = 1;
    while (h < N/3) h = 3 * h + 1; // 1, 4, 13, 40, 121, 364...
    while (h >= 1)
    {
        for (int i = h; i < N; ++i)
        {
            for (int j = i; j >= h && less(a[j], a[j - h]); j -= h)
                exch(a, j, j-h);
        }
        h = h / 3;
    }
}

int main() {
    vector<int> a{4,5,3,2,1};
    Example_sort<int> solver;
    solver.shell_sort(a);
    solver.show(a);
    
}