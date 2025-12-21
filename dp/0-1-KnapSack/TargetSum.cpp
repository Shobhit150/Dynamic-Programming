#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int ways = 0;
    void bruteForce(vector<int>& nums, int i, int target) {
        if(i==nums.size()) {
            if(target == 0) ways++;
            return;
        }
        bruteForce(nums, i+1, target-nums[i]);
        bruteForce(nums, i+1, target+nums[i]);
    }
    
    int memorization(vector<int>& nums, int i, int target, vector<vector<int>>&dp) {
        if(i==nums.size()) {
            if(target==0) return 1;
            return 0;
        }
        if(dp[i][1000+target] != -1) return dp[i][1000+target];

        int add = memorization(nums, i+1, target+nums[i], dp);
        int sub = memorization(nums, i+1, target-nums[i], dp);
        dp[i][1000+target] = add + sub;
        return dp[i][1000+target];


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // bruteForce(nums, 0, target);
        // return ways;
        vector<vector<int>> dp(21, vector<int>(2002,-1));
        return memorization(nums, 0,target, dp);




    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target);
}