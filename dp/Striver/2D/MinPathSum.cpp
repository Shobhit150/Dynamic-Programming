#include<iostream>
using namespace std;
class Solution {
public:
    int bruteForce(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i==m || j==n) return INT_MAX/2;

        int bottom = grid[i][j] + bruteForce(grid,m,n,i+1,j);
        int right = grid[i][j] + bruteForce(grid,m,n,i,j+1);
        return min(bottom,right);
    }
    int memo(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>> &dp) {
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i==m || j==n) return INT_MAX/2;
        if(dp[i][j] != -1) return dp[i][j];

        int bottom = grid[i][j] + memo(grid,m,n,i+1,j,dp);
        int right = grid[i][j] + memo(grid,m,n,i,j+1,dp);
        dp[i][j] = min(bottom,right);
        return min(bottom,right);
    }
    int tab(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) continue;
                int bottom = INT_MAX;
                if(i>=1) bottom = grid[i][j] + dp[i-1][j];
                int right = INT_MAX;
                if(j>=1) right = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(right, bottom);
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return tab(grid,m,n);
    }
};