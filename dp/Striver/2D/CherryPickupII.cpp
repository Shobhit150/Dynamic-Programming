#include <iostream>
using namespace std;


class Solution {
public:
    int bruteForce(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(c1<0 || c2<0 || c1==grid[0].size() || c2 == grid[0].size()) return INT_MIN/2;
        if(row == grid.size()-1) {
            if (c1 == c2) return grid[row][c1];
            return grid[row][c1] + grid[row][c2];
        }
        int res = INT_MIN/2;
        res = max(res,bruteForce(grid, row+1, c1-1, c2-1));
        res = max(res,bruteForce(grid, row+1, c1, c2-1));
        res = max(res,bruteForce(grid, row+1, c1+1, c2-1));
        res = max(res,bruteForce(grid, row+1, c1-1, c2));
        res = max(res,bruteForce(grid, row+1, c1, c2));
        res = max(res,bruteForce(grid, row+1, c1+1, c2));
        res = max(res,bruteForce(grid, row+1, c1-1, c2+1));
        res = max(res,bruteForce(grid, row+1, c1, c2+1));
        res = max(res,bruteForce(grid, row+1, c1+1, c2+1));

        int value = grid[row][c1];
        if(c1 != c2) value += grid[row][c2];

        return value + res;
    }
    int memo(vector<vector<int>>& grid, int row, int c1, int c2, vector<vector<vector<int>>>& dp) {
        if(c1<0 || c2<0 || c1==grid[0].size() || c2 == grid[0].size()) return INT_MIN/2;
        if(row == grid.size()-1) {
            if (c1 == c2) return grid[row][c1];
            return grid[row][c1] + grid[row][c2];
        }
        if(dp[row][c1][c2] != -1) return dp[row][c1][c2];
        int res = INT_MIN/2;
        res = max(res,memo(grid, row+1, c1-1, c2-1,dp));
        res = max(res,memo(grid, row+1, c1, c2-1,dp));
        res = max(res,memo(grid, row+1, c1+1, c2-1,dp));
        res = max(res,memo(grid, row+1, c1-1, c2,dp));
        res = max(res,memo(grid, row+1, c1, c2,dp));
        res = max(res,memo(grid, row+1, c1+1, c2,dp));
        res = max(res,memo(grid, row+1, c1-1, c2+1,dp));
        res = max(res,memo(grid, row+1, c1, c2+1,dp));
        res = max(res,memo(grid, row+1, c1+1, c2+1,dp));

        int value = grid[row][c1];
        if(c1 != c2) value += grid[row][c2];

        return dp[row][c1][c2] = value + res;
    }
    int tab(vector<vector<int>>& grid, int m, int n) {
        vector<vector<vector<int>>> dp(m,
    vector<vector<int>>(n, vector<int>(n, INT_MIN/2)));
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = 0; c2 < n; c2++) {
                if (c1 == c2)
                    dp[m-1][c1][c2] = grid[m-1][c1];
                else
                    dp[m-1][c1][c2] = grid[m-1][c1] + grid[m-1][c2];
            }
        }

        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    int res = INT_MIN/2;
                    if(j-1 >= 0 && k-1 >=0) res = max(res, dp[i+1][j-1][k-1]);
                    if(k-1 >=0) res = max(res, dp[i+1][j][k-1]);
                    if(j+1 < n && k-1 >=0) res = max(res, dp[i+1][j+1][k-1]);
                    if(j-1 >= 0) res = max(res, dp[i+1][j-1][k]);
                    res = max(res, dp[i+1][j][k]);
                    if(j+1 < n) res = max(res, dp[i+1][j+1][k]);
                    if(j-1 >= 0 && k+1 < n) res = max(res, dp[i+1][j-1][k+1]);
                    if(k+1 < n) res = max(res, dp[i+1][j][k+1]);
                    if(j+1 < n && k+1 < n) res = max(res, dp[i+1][j+1][k+1]);
                    dp[i][j][k] = grid[i][j];
                    if(j!=k) dp[i][j][k] += grid[i][k];
                    dp[i][j][k] += res;
                }
            }
        }
        return dp[0][0][n-1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
        return tab(grid, m, n);
    }
};
