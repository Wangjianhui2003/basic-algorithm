#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// 回溯实现不重复组合
int main() {
    vector<int> vec({ 1,2,3,4,5 });
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> selected(vec.size());
    auto dfs = [&](auto&& dfs, int n, int j) -> void {
        if (n == 0) {
            ans.push_back(path);
        }

        for (int i = j;i < vec.size();i++) {
            if (selected[i] == false) {
                selected[i] = 1;
                path.push_back(vec[i]);
                dfs(dfs, n - 1, i);
                path.pop_back();
                selected[i] = 0;
            }
        }
        };

    dfs(dfs, 3, 0);

    for (auto v : ans) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
}
