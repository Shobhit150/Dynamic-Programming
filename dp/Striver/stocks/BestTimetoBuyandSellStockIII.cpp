#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    int bruteForce(vector<int>& prices, int i, bool canBuy, int times) {
        if(i==prices.size()) {
            if(canBuy) return 0;
            return INT_MIN/2;
        }
        if(times == 3) return 0;
        if(canBuy) {
            return max(-prices[i] + bruteForce(prices, i+1, !canBuy, times),
                    bruteForce(prices, i+1, canBuy, times));
        }
        return max(prices[i] + bruteForce(prices, i+1, !canBuy, times + 1),
                    bruteForce(prices, i+1, canBuy, times));
    }
    int tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    if(j==0) { // canBuy
                        dp[i][j][k] = max(-prices[i] + dp[i+1][1][k], dp[i+1][0][k]);
                    } else {
                        dp[i][j][k] = max(prices[i] + dp[i+1][0][k+1], dp[i+1][1][k]);
                    }
                }
            }
        }
       
        return dp[0][0][0];
    }


    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        return tab(prices);
    }

    
    
};

int main() {
	Solution s;
    
	vector<int> prices = {3,3,5,0,0,3,1,4};
    
   
	cout << s.maxProfit(prices);
}
