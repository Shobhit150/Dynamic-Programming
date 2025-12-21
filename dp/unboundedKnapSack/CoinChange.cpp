#include <iostream>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;
    void bruteForce(vector<int>& coins, int amount, int idx, int coinCount) {
        if(amount == 0) {
            ans = min(ans, coinCount);
            return;
        }
        if(amount < 0) return;
        
        for(int i=idx;i<coins.size();i++) {
            bruteForce(coins, amount-coins[i], i, coinCount + 1);
        }
    }
    int memorization(vector<int>& coins, int amount,int idx,vector<int>& dp ) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) return INT_MAX/2;
        if(dp[amount] != -1) return dp[amount];
        int sum = 0;
        int min1 = INT_MAX/2;
        
        for(int i=idx;i<coins.size();i++) {
            sum += coins[i];
            min1 = min(min1, 1 + memorization(coins,amount-coins[i], i, dp));
        }
        dp[amount] = min1;
        return min1;
    }
    int coinChange(vector<int>& coins, int amount) {
        // bruteForce(coins, amount, 0, 0);
        // return ans;
        vector<int> dp(amount+1,-1);
        return memorization(coins,amount,0, dp);
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << s.coinChange(coins, amount);
}