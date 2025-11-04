#include <iostream>
#include <queue>

using namespace std;
/**
 * 4种二分查找情况
 */

//上边界
int bs_upperbound(vector<int>& vec,int num){
    int left = 0, right = vec.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(vec[mid] <= num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return right;
}

//上边界 + 1
int bs_upperbound2(vector<int>& nums,int num){
    int left = 0,right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] <= num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left; 
}

//下边界
int bs_lowerbound(vector<int>& nums,int num){
    int left = 0,right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    vector<int> vec = {1,2,3,4,4,4,4,5,6,7};
    cout<<bs_upperbound2(vec,4)<<endl;
}
