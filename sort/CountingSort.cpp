#include <iostream>
#include <queue>
#include <ranges>
#include <numeric>

using namespace std;

/**
 * 计数排序
 */

//按最大桶
void counting_sort(vector<int>& nums, int max) {
    vector<int> bucket(max + 1);
    for (int x : nums) {
        bucket[x]++;
    }
    int k = 0;
    for (int i = 0;i < bucket.size();i++) {
        while (bucket[i] > 0) {
            nums[k] = i;
            k++;
            bucket[i]--;
        }
    }
}

int main() {
    vector<int> nums = { 1,4,6,7,23,4,4,1,9 ,4,7,8,0,3,2,2,4 };
    counting_sort(nums, 23);
    for (int i : nums) cout << i << " ";
}


