#include<iostream>
using namespace std;

class Solution {
public:
    int ways = 0;
    void bruteforce(int n, int minProfit, vector<int>& group, vector<int>& profit, int i, int currProfit) {
        if(i==group.size()) {
            if(currProfit >= minProfit) {
                ways++;
            }
            return;
        }
        if(n >= group[i]) {
            bruteforce(n-group[i],minProfit,group, profit, i+1, currProfit + profit[i]);
        }
        bruteforce(n,minProfit,group, profit, i+1, currProfit);
    }
    int memorization(int n, int minProfit, vector<int>& group, vector<int>& profit, int i, int currProfit, vector<vector<vector<int>>> &dp) {
        if(i==group.size()) {
            if(currProfit >= minProfit) {
                return 1;
            }
            return 0;
        }
        if(dp[n][i][currProfit] != -1) return dp[n][i][currProfit];
        int tot = 0;
        if(n >= group[i]) {
            int newProfit = min(minProfit, currProfit + profit[i]);
            tot += memorization(n-group[i],minProfit,group, profit, i+1, newProfit, dp);
        }
        tot += memorization(n,minProfit,group, profit, i+1, currProfit, dp);
        dp[n][i][currProfit] = tot;
        return tot;

    }
    int tabularization(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(group.size()+1, vector<int>(minProfit+1, -1)));

        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // bruteforce(n,minProfit,group,profit,0,0);
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(group.size()+1, vector<int>(minProfit+1, -1)));
        return memorization(n, minProfit, group, profit, 0, 0, dp);
        // return ways;
    }
};

int main() {
    int n = 5;
    int minProfit = 3;
    vector<int> group = {2,2};
    vector<int> profit = {2,3};
    Solution s;
    cout << s.profitableSchemes(n,minProfit,group,profit);
}