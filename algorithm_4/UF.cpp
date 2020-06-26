#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// findc操作的速度显然是很快的,因为它只需要访问id[]数组一次。但quik-fnd算法一般
// 无法处理大型问题,因为对于每一对输人 union)都需要扫描整个id[]数组。
/**
 * 在 quick-find算法中,每次 find()调用只需要访问数组一次,而归并两个分量的
 * union()操作访问数组的次数在(N+3)到(2N+1)之间。
*/
class quick_Find
{
    vector<int> id; // 连通域 id
    int count;      // 连通域数量
public:
    quick_Find(int N) : count(N) {
        id = vector<int>(N);
        iota(id.begin(), id.end(), 0); // 数组内从 0 填充到 N-1
    }
    int count() { return count; };
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) { return id[p]; }
    void unite(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        // 如果p和q已经在相同的分量之中则不需要采取任何行动
        if (pID == qID) return;

        // 将p的分量重命名为q的名称
        for (int i = 0; i < id.size(); ++i)
            if (id[i] == pID) id[i] = qID;
        count--;
    }
};

/*
* quick-union算法中的find()方法访问数组的次数为1加上给定触点所对应的节点的
* 深度的两倍。 union()和connected()访问数组的次数为两次find()操作(如果 union()中
* 给定的两个触点分别存在于不同的树中则还需要加 1)。
*/
class quick_Union
{
    vector<int> id; // 连通域 id
    int count;      // 连通域数量
public:
    quick_Union(int N) : count(N) {
        id = vector<int>(N);
        iota(id.begin(), id.end(), 0); // 数组内从 0 填充到 N-1
    }
    int count() { return count; };
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) {
        // 找出分量的名称
        while (p != id[p]) p = id[p];
        return p;
    }
    void unite(int p, int q) {
        // 将p和q的根节点统一
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot = qRoot) return;

        id[pRoot] = qRoot;
        count--;
    }
};

// 加权quick-union方法
// 对于N个触点,加权 quick-union算法构造的森林中的任意节点的深度最多为lgN
// 推论。对于加权 quick- union算法和N个触点,在最坏情况下 find()、 connected()和
// union()的成本的增长数量级为logN
class WeighedQuickUnionUF
{
    vector<int> id; // 连通域 id
    vector<int> sz; // 各个根节点所对应的分量的大小
    int count;      // 连通域数量
public:
    WeighedQuickUnionUF(int N) : count(N) {
        id = vector<int>(N);
        sz = vector<int>(N, 1);
        iota(id.begin(), id.end(), 0); // 数组内从 0 填充到 N-1
    }
    int count() { return count; };
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) { return id[p]; }
    void unite(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        // 将小树的根节点连接到大树的根节点
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        count--;
    }
};

class quick_Union
{
    vector<int> id; // 连通域 id
    int count;      // 连通域数量
public:
    quick_Union(int N) : count(N) {
        id = vector<int>(N);
        iota(id.begin(), id.end(), 0); // 数组内从 0 填充到 N-1
    }
    int count() { return count; };
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int find(int p) {
        // 找出分量的名称
        while (p != id[p]) p = id[p];
        return p;
    }
    void unite(int p, int q) {
        // 将p和q的根节点统一
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot = qRoot) return;

        id[pRoot] = qRoot;
        count--;
    }
};

// 加权quick-union方法
// 对于N个触点,加权 quick-union算法构造的森林中的任意节点的深度最多为lgN
// 推论。对于加权 quick- union算法和N个触点,在最坏情况下 find()、 connected()和
// union()的成本的增长数量级为logN
class QuickUnionPathCompressionUF
{
    vector<int> id; // 连通域 id
    int count;      // 连通域数量
public:
    QuickUnionPathCompressionUF(int N) : count(N) {
        id = vector<int>(N);
        iota(id.begin(), id.end(), 0); // 数组内从 0 填充到 N-1
    }
    int count() { return count; };
    bool connected(int p, int q) {
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    int find(int p) { return id[p]; }
    void unite(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        id[i] = j;
        count--;
    }
};