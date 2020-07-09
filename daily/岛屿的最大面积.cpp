#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class UF {
    vector<int> parents;
    vector<int> areas;
public:
    int max_area;
    UF(int n) : max_area(0) {
        parents = vector<int> (n);
        iota(parents.begin(), parents.end(), 0);
        areas = vector<int> (n, 0);
    }
    void make_stone(int index) { areas[index]++; max_area = 1; }
    int find(int index) {
        return index == parents[index] ? index : find(parents[index]);
    }
    void unite(int index1, int index2) {
        int root1 = find(index1);
        int root2 = find(index2);
        if (root1 != root2) {
            areas[root1] += areas[root2];
            max_area = max(max_area, areas[root1]);
            parents[root2] = root1;
        }
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        UF uf(N);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1){
                    int temp = i * m + j;
                    uf.make_stone(temp);
                }
            }
        }
        if (uf.max_area == 0) return 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (i > 0 && grid[i - 1][j] == 1) {
                        int tmp1 = (i - 1) * m + j;
                        int tmp2 = i * m + j;
                        uf.unite(tmp1, tmp2);
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        int tmp1 = i * m + j - 1;
                        int tmp2 = i * m + j;
                        uf.unite(tmp1, tmp2);
                    }
                }
            }
        }
        return uf.max_area;
    }
};

int main() {
    vector<vector<int>> nums = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    Solution solver;
    auto x = solver.maxAreaOfIsland(nums);
    cout << x << endl;
    return 0;
}