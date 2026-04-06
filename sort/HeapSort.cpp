#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void heapSort(vector<int> &nums) {
        int n = nums.size();
        for (int k = n / 2 - 1; k >= 0; k--) {
            siftDown(nums, k, n);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            siftDown(nums, 0, i);
        }
    }

    void siftDown(vector<int> &nums, int k, int heapSize) {
        while (k < heapSize / 2) { // 不是叶子结点就循环
            int largest = k * 2 + 1;
            int right = k * 2 + 2;
            if (right < heapSize && nums[right] > nums[largest]) {
                largest = right;
            }
            if (nums[k] > nums[largest])
                break;
            swap(nums[k], nums[largest]);
            k = largest;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 4, 6, 7, 23, 4, 4, 1, 9};
    solution.heapSort(nums);
    for (int i : nums)
        cout << i << " ";
}
