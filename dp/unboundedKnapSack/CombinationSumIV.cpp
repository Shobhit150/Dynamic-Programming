#include<iostream>
using namespace std;

class Solution {
public:
    int ans = 0;
    void bruteForce(vector<int>& nums, int target) {
        if(target == 0) {
            ans++;
            return;
        }
        if(target < 0) return;

        for(int i=0;i<nums.size();i++) {

            bruteForce(nums, target - nums[i]);
        }
    }
    int memo(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) {
            return 1;
        }
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += memo(nums, target - nums[i], dp);
        }
        return dp[target] = sum;

    }
    int combinationSum4(vector<int>& nums, int target) {
        
        // bruteForce(nums, target);
        // return ans;

        vector<int> dp(target+1, -1);
        return memo(nums, target, dp);
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2,3};
    int target = 4;
    cout << s.combinationSum4(coins, target);
}