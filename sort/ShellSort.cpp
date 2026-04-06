#include <bits/stdc++.h>
using namespace std;

/**
 * 插入排序是稳定的，希尔排序是不稳定的
 */
void ShellSort(vector<int> &nums) {
    int n = nums.size();
    int i, j, temp;
    for (int d = n / 2; d >= 1; d /= 2) {
        for (i = d; i < n; i++) {
            // 插入排序
            if (nums[i] < nums[i - d]) {
                temp = nums[i];
                for (j = i - d; j >= 0 && nums[j] > temp; j -= d) {
                    nums[j + d] = nums[j];
                }
                nums[j + d] = temp;
            }
        }
    }
}

int main() {
    vector<int> nums = {4, 6,   8, 1, 2, 0, 1, 2, 7, 10,
                        5, 111, 0, 3, 5, 9, 4, 6, 0};
    int n = 19;
    ShellSort(nums);
    for (int x : nums)
        cout << x << " ";
}
