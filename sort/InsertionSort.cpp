#include <iostream>
#include <vector>
using namespace std;

/**
 * 将数插入到比它大的的前面，比它小的后面
 */

void InsertSort(vector<int>& nums) {
    int n = nums.size();
    int i, j, temp;
    for (i = 1;i < n;i++) {
        if (nums[i] < nums[i - 1]) {
            temp = nums[i];
            for (j = i - 1;j >= 0 && nums[j] > temp;j--) {
                nums[j + 1] = nums[j];  //往后移动一位
            }
            //j--后遇到不大于的数，取后面那个
            nums[j + 1] = temp;
        }
    }
}

/**
 * 带哨兵
 */
void InsertSort2(int r[], int n) {
    int j;
    for (int i = 2;i <= n;i++) {
        r[0] = r[i];        //r[0]是监视哨
        //顺序比较和移动，查找r[i]的插入位置
        for (j = i - 1;r[0] < r[j];j--){
            r[j + 1] = r[j]; //记录后移，继续向前搜索 
        }
        r[j + 1] = r[0];      //插入r[i]
    }
}

int main() {
    vector<int> nums = { 16,3,1,6,7,4 };
    InsertSort(nums);
    for (int x : nums) cout << x << " ";
}

