#include<iostream>
using namespace std;

class Solution {
public:
    
    int bruteForce(vector<int>& wt, vector<int> &val, int n, int i, int currLeft) {
        if(currLeft < 0) {
            return INT_MIN/2;
        }
        if(i==n) {
            return 0;
        }
        

        int skip = bruteForce(wt, val, n, i+1, currLeft);
        int take = val[i] + bruteForce(wt, val, n, i+1, currLeft - wt[i]);

        return max(skip, take);
    }
    int memo(vector<int>& wt, vector<int> &val, int n, int i, int currLeft, vector<vector<int>> &dp) {
        if(currLeft < 0) {
            return INT_MIN/2;
        }
        if(i==n) {
            return 0;
        }
        if(dp[i][currLeft] != -1) return dp[i][currLeft];
        

        int skip = memo(wt, val, n, i+1, currLeft, dp);
        int take = val[i] + memo(wt, val, n, i+1, currLeft - wt[i], dp);

        return dp[i][currLeft] = max(skip, take);
    }
    int tab(vector<int>& wt, vector<int> &val, int n, int W) {
        vector<vector<int>> dp(n+1, vector<int>(W+1,0));
        for(int i=n-1;i>=0;i--) {
            for(int currLeft = 0;currLeft<=W;currLeft++) {
                int skip = dp[i+1][currLeft];
                int take = INT_MIN/2;
                if(currLeft - wt[i] >= 0) {
                    take = val[i] + dp[i+1][currLeft - wt[i]];
                }
                dp[i][currLeft] = max(skip, take);
            }
        }
        return dp[0][W];
    }
    int KnapSack(vector<int>& wt, vector<int> &val, int n, int W) {
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        return tab(wt, val, n, W);
    }
};


int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();

    Solution s;
    cout << "Ans: " << s.KnapSack(wt, val, n, W);

    return 0;
}
