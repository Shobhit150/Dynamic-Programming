#include<iostream>
using namespace std;

class Solution {
    public:
    int bruteForce(vector<int>& wt, vector<int>& val, int n, int currLeft) {
        if(currLeft < 0) {
            return INT_MIN/2;
        }
        if(currLeft == 0) {
            return 0;
        }
        int res = INT_MIN/2;
        for(int i=0;i<n;i++) {
            res = max(res, val[i] + bruteForce(wt, val, n, currLeft - wt[i]));
        }
        return res;

    }
    int memo(vector<int>& wt, vector<int>& val, int n, int currLeft, vector<int>& dp) {
        if(currLeft < 0) {
            return INT_MIN/2;
        }
        if(currLeft == 0) {
            return 0;
        }
        if(dp[currLeft] != -1) return dp[currLeft];
        int res = INT_MIN/2;
        for(int i=0;i<n;i++) {
            res = max(res, val[i] + memo(wt, val, n, currLeft - wt[i], dp));
        }
        return dp[currLeft] = res;

    }
    int tab(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> dp(W+1,0);
        for(int i=W-1;i>=0;i--) {
            int res = INT_MIN/2;
            for(int j=0;j<n;j++) {
                if(i + wt[j] <= W) {
                    res = max(res, val[j] + dp[i + wt[j]]);
                }
            }
            dp[i] = res;
        }
        return dp[0];
    }
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> dp(W+1,-1);
        return tab(wt, val, n, W);
    }
};



int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();

    Solution s;
    cout << "Ans: " << s.unboundedKnapsack(wt, val, n, W);

    return 0;
}
