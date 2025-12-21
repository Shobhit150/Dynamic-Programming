#include<iostream>
using namespace std;

class Solution {
public:
    int bruteForce(int n, vector<int> &squares) {
        if(n==0) return 0;

        int min1 = INT_MAX/2;
        for(int i=0;i<squares.size();i++) {
            if(n>=squares[i]) {
                min1 = min(min1,1 + bruteForce(n-squares[i], squares));
            }
        }
        return min1;

    }
    int memo(int n, vector<int> &squares, vector<int>& dp) {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int min1 = INT_MAX/2;
        for(int i=0;i<squares.size();i++) {
            if(n>=squares[i]) {
                min1 = min(min1,1 + memo(n-squares[i], squares,dp));
            }
        }
        dp[n]=min1;
        return min1;

    }
    int numSquares(int n) {
        // vector<int> squares;
        // for(int i=1;i*i<n;i++) {
        //     squares.push_back(i*i);
        // }
        // return bruteForce(n,squares);
        vector<int> squares;
        for(int i=1;i*i<=n;i++) {
            squares.push_back(i*i);
        }
        vector<int> dp(n+1,-1);
        return memo(n,squares,dp);
    }
};

int main() {
    Solution s;
    int n = 12;
    cout << s.numSquares(n);
}