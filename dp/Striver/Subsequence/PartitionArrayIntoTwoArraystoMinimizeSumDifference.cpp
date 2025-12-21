#include <iostream>
using namespace std;

// total = left + currentTotal
// left = total - currentTotal
// left - currentTotal = total - 2*currentTotal

class Solution {
public:
    int bruteForce(vector<int>& nums, int i, int total, int currentTotal) {
        if(i==nums.size()) {
            return abs(total - (2*currentTotal));
        }

        int take = bruteForce(nums, i+1, total, currentTotal + nums[i]);
        int skip = bruteForce(nums, i+1, total, currentTotal);
        return min(take, skip);
    }
    int memo(vector<int>& nums, int i, int total, int currentTotal, vector<vector<int>>& dp) {
        if(i==nums.size()) {
            return abs(total - (2*currentTotal));
        }
        if(dp[i][currentTotal] != -1) return dp[i][currentTotal];

        int take = memo(nums, i+1, total, currentTotal + nums[i], dp);
        int skip = memo(nums, i+1, total, currentTotal, dp);
        return dp[i][currentTotal] = min(take, skip);
    }
    int tab(vector<int>& nums, int n, int total) {
        vector<vector<int>> dp(n+1, vector<int>(total+1,0));
        for(int j=0;j<=total;j++) {
            dp[n][j] = abs(total - 2*j);
        }
        for(int i=n-1;i>=0;i++) {
            for(int j=0;j<=total;j++) {
                int take = INT_MAX;
                if(j+nums[i] <= total){
                    int take = dp[i+1][j + nums[i]];
                }
                int skip = dp[i+1][j];

                dp[i][j] = min(take, skip);
            }
        }
        return dp[0][0];

    }
    int minimumDifference(vector<int>& nums) {
        int total = 0;
        for(int& num: nums) total += num;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(total+1,-1));
        return memo(nums, 0, total, 0, dp);
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 7, 14, 5};
    int ans = s.minimumDifference(nums);
    cout << ans;
}