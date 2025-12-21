#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int bruteForce(vector<vector<int>>& triangle, int i, int j) {
        if(i==triangle.size()) return 0;
        if(j==triangle[i].size()) return INT_MAX/2;

        int right = bruteForce(triangle, i+1,j);
        int left = bruteForce(triangle, i+1,j+1);
        return min(right, left) + triangle[i][j];

    }
    int memo(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if(i==triangle.size()-1) return triangle[i][j];
        if(j==triangle[i].size()) return INT_MAX/2;
        if(dp[i][j] != -1) return dp[i][j];

        int right = memo(triangle, i+1,j,dp);
        int left = memo(triangle, i+1,j+1,dp);
        return dp[i][j] = triangle[i][j] + min(right, left);
    }
    int tab(vector<vector<int>>& triangle, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<n;i++) {
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<triangle[i].size();j++) {
                int right = dp[i+1][j];
                int left = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(right, left);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        // vector<vector<int>> dp(m);
        // for(int i = 0; i < m; i++)
        //     dp[i].assign(triangle[i].size(), -1);
        return tab(triangle, m, n);
    }
};