#include <iostream>
#include <queue>

using namespace std;

// 平均nlogn
// 最坏退化成n ^ 2
// 递归关系：
// T(n) = T(n - 1) + O(n)
// 
// 假设这次选的 pivot 恰好是最小值，那么一趟划分之后会变成：
// 左边：0 个元素
// 右边：n - 1 个元素
// 这时这一层做了两件事：
// 划分整个长度为 n 的数组，花 O(n)
// 递归处理那个长度为 n - 1 的子数组，花 T(n - 1)

//随机选一个
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int pivot = nums[l + rand() % (r - l + 1)];
    int i = l;
    //left指向的是所有<=pivot的数,right反之
    int left = l - 1, right = r + 1;
    while (i < right) {
        if (nums[i] < pivot) {
            left++;
            swap(nums[i], nums[left]);
            i++;
        }
        else if (nums[i] == pivot) {
            i++;
        }
        else {
            right--;
            swap(nums[i], nums[right]);
        }
    }
    quick_sort(nums, l, left);
    quick_sort(nums, right, r);
}

//最左元素为pivot
void quick_sort_l(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] >= nums[l]) j--;
        while (i < j && nums[i] <= nums[l]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);
    quick_sort_l(nums, l, i - 1);
    quick_sort_l(nums, i + 1, r);
}

//以最左边的数为pivot
int partition(vector<int>& nums, int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[i] <= nums[j]) j--;
        if (i < j) {
            swap(nums[i], nums[j]);
            i++;
        }
        while (i < j && nums[i] <= nums[j]) i++;
        if (i < j) {
            swap(nums[i], nums[j]);
            j--;
        }
    }
    return i;
}

void quick_sort2(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pivot = partition(nums, left, right);
        quick_sort2(nums, left, pivot - 1);
        quick_sort2(nums, pivot + 1, right);
    }
}


int main() {
    vector<int> nums = { 1,4,6,7,23,4,4,1,9,4,7,8,0,3,2,2,4 };
    // quick_sort(nums, 0, nums.size() - 1);
    quick_sort2(nums, 0, nums.size() - 1);
    for (int i : nums) cout << i << " ";
}


