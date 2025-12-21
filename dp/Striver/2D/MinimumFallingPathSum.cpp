#include<iostream>
using namespace std;
class Solution {
public:
    int bruteForce(vector<vector<int>>& matrix, int n, int i, int j) {
        if(j<0 || j==n) return INT_MAX/2;
        if(i==n-1) return matrix[i][j];

        int right = bruteForce(matrix, n, i+1,j+1);
        int mid = bruteForce(matrix, n, i+1,j);
        int left = bruteForce(matrix, n, i+1,j-1);
        return matrix[i][j] + min({right, mid, left});
    }
    int memo(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>> &dp) {
        if(j<0 || j==n) return INT_MAX/2;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int right = memo(matrix, n, i+1,j+1,dp);
        int mid = memo(matrix, n, i+1,j,dp);
        int left = memo(matrix, n, i+1,j-1,dp);
        return dp[i][j] = matrix[i][j] + min({right, mid, left});
    }
    int tab(vector<vector<int>>& matrix, int n) {
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++) {
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                int left = INT_MAX/2;
                if(j>=1) left = dp[i+1][j-1];
                int mid = dp[i+1][j];
                int right = INT_MAX/2;
                if (j+1 < n) right = dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + min({left, mid, right});
            }
        }
        int min1 = INT_MAX;
        for(int i=0;i<n;i++) {
            min1 = min(min1, dp[0][i]);
        }
        return min1;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min1 = INT_MAX;

        // for(int i=0;i<n;i++) {
        //     vector<vector<int>> dp(n,vector<int>(n,-1));
        //     min1 = min(min1, memo(matrix, n, 0, i, dp));
        // }
        return tab(matrix, n);
    }
};