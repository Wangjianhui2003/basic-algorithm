#include <bits/stdc++.h>

using namespace std;
/**
 * 冒泡排序
 * 最小的在最后面，要n-1次冒到第一个
 */

class Solution {
public:
  void BubbleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = n - 1; j > i; j--) {
        if (nums[j - 1] > nums[j]) {
          swap(nums[j - 1], nums[j]);
        }
      }
    }
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 4, 6, 7, 23, 4, 4, 1, 9, 4, 7, 8, 0, 3, 2, 2, 4};
  solution.BubbleSort(nums);
  for (int i : nums)
    cout << i << " ";
}
