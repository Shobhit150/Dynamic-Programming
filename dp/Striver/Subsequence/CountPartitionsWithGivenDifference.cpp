#include <iostream>
using namespace std;

// restSum = total - currentSum
// restSum - currentSum = total - 2*currentSum
// diff = total - 2*currentSum
// 
class Solution {
    public:
    int bruteForce(vector<int>& arr, int i, int currentSum, int total, int diff) {
        
        if(i==arr.size()) {
            if(total - (2*currentSum) == diff) return 1;
            return 0;
        }

        int take = bruteForce(arr, i+1, currentSum + arr[i], total, diff);
        int skip = bruteForce(arr, i+1, currentSum, total, diff);
        return take + skip;
    }
    int memo(vector<int>& arr, int i, int currentSum, int total, int diff, vector<vector<int>>& dp) {
        
        if(i==arr.size()) {
            if(total - (2*currentSum) == diff) return 1;
            return 0;
        }
        if(dp[i][currentSum] != -1) return dp[i][currentSum];

        int take = memo(arr, i+1, currentSum + arr[i], total, diff, dp);
        int skip = memo(arr, i+1, currentSum, total, diff, dp);
        return dp[i][currentSum] = take + skip;
    }
    int tab(vector<int>& arr, int n, int diff, int total) {
        int val = total - diff;
        if (val < 0 || val % 2 != 0) return 0;
        int target = val / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[n][(total - diff)/2] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int s=0;s<target;s++) {
                int skip = dp[i+1][s];
                int take = 0;
                if(s+arr[i] < total) {
                    take = dp[i+1][s+arr[i]];
                }
                dp[i][s] = skip + take;
            }
        }
        return dp[0][0];
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int total = 0;
        for(int& num: arr) total += num;
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
        return memo(arr, 0, 0, total, diff, dp);
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    int n = arr.size();
    int ans = s.countPartitions(n, diff, arr);
    cout << ans;
}