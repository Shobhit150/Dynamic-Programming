#include <iostream>
#include <vector>
#include<cmath>
using namespace std;


class Solution {
public:
    // int ans = INT_MAX;
    
    // void bruteForce(vector<int>& nums, int i, int curr) {
    //     if(i==nums.size()) {
    //         ans = min(abs(curr), ans);
    //         return;
    //     }

    //     bruteForce(nums, i+1, curr+nums[i]);
    //     bruteForce(nums, i+1, curr-nums[i]);
        
    // }
    int memorization(vector<int>& nums, int i, int curr, vector<vector<int>> &dp) {
        if(i==nums.size()) {
            return abs(curr);
        }
        if(dp[i][curr+3000] != -1) return dp[i][curr+3000];

        int sub = memorization(nums, i+1, curr - nums[i], dp);
        int add = memorization(nums, i+1, curr + nums[i], dp);

        dp[i][3000+curr] = min(sub,add);
        return dp[i][3000+curr];
    }
    
    int lastStoneWeightII(vector<int>& nums) {
        // bruteForce(nums,0,0);
        vector<vector<int>> dp(30,vector<int>(6000,-1));
        int ans = memorization(nums, 0, 0, dp);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {31,26,33,21,40};
    cout << s.lastStoneWeightII(nums);
}