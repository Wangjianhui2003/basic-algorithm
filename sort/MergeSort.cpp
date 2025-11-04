#include <iostream>
#include <queue>

using namespace std;

void merge(vector<int>& nums, int left, int right, int mid, vector<int>& temp);

//归并排序
void merge_sort(vector<int>& nums, int left, int right, vector<int>& temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(nums, left, mid, temp);
        merge_sort(nums, mid + 1, right, temp);
        merge(nums, left, right, mid, temp);
    }
}

//合并
void merge(vector<int>& nums, int left, int right, int mid, vector<int>& temp) {
    int i = left, j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            temp[k] = nums[i++];
        }
        else {
            temp[k] = nums[j++];
        }
        k++;
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    for (int i = left;i <= right;i++) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> nums = { 4,6,8,1,2,0,1,2,7,10,5,111,0,3,5,9,4,6,0 };
    int n = nums.size();
    vector<int> temp(n);
    merge_sort(nums,0,n - 1,temp);
    for (int i = 0;i < n;i++) {
        cout << nums[i] << " ";
    }
}


