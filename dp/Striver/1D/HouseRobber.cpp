#include<iostream>
#include<vector>
using namespace std;

int bruteForce(vector<int>& nums, int i) {
    if(i==0) return 0;
    if (i < 0) return 0;
    
    int left = bruteForce(nums, i-1);
    int right = nums[i+1] + bruteForce(nums, i-2);

    return max(left, right);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    return bruteForce(nums,n);
}

int main() {
    vector<int> nums = {1,2,3,4,5,1,2,3,4,5};
    int ans = rob(nums);
    cout << ans << endl;
}