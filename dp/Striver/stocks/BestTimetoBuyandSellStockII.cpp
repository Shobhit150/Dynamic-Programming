#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int bruteForce(vector<int>& prices, int i, bool canBuy) {
        if(i == prices.size()) {
            if(canBuy) return 0;
            return INT_MIN/2;
        }

        if(canBuy) {
            return max( 0 + bruteForce(prices, i+1, canBuy), 
                    -prices[i] + bruteForce(prices, i+1, !canBuy));
        }
        return max( 0 + bruteForce(prices, i+1, canBuy), 
                    prices[i] + bruteForce(prices, i+1, !canBuy));
    }
    int memo(vector<int>& prices, int i, bool canBuy,vector<vector<int>> &dp) {
        if(i == prices.size()) {
            if(canBuy) return 0;
            return INT_MIN/2;
        }
        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy) {
            return dp[i][canBuy] = max( 0 + memo(prices, i+1, canBuy, dp), 
                    -prices[i] + memo(prices, i+1, !canBuy,dp));
        }
        return dp[i][canBuy] = max( 0 + memo(prices, i+1, canBuy,dp), 
                    prices[i] + memo(prices, i+1, !canBuy,dp));
    }
    int tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = INT_MIN/2;
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                if(j==1) {
                    dp[i][1] = max(dp[i+1][1] ,
                            -prices[i] + dp[i+1][0]);
                } else {
                    dp[i][0] = max(dp[i+1][0], prices[i] + dp[i+1][1]);
                }
            }
        }
        return dp[0][1];

    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
	    return tab(prices); 
    }
    
    
};

int main() {
	Solution s;
    
	vector<int> prices = {7,1,5,3,6,4};
    
   
	cout << s.maxProfit(prices);
}
