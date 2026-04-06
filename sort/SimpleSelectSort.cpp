#include <bits/stdc++.h>
using namespace std;

/**
 * 简单选择排序
 */

void SimpleSelectSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k]) { // 选出最小的
                k = j;
            }
        }
        if (k != i)
            swap(nums[i], nums[k]);
    }
}

int main() {
    vector<int> nums = {4, 6,   8, 1, 2, 0, 1, 2, 7, 10,
                        5, 111, 0, 3, 5, 9, 4, 6, 0};
    int n = 19;
    SimpleSelectSort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}
