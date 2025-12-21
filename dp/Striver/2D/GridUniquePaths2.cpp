#include <iostream>
using namespace std;

int bruteForce(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j) {
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;
    if(obstacleGrid[i][j] == 1) return 0;
    int down = bruteForce(obstacleGrid,m,n,i+1,j);
    int right = bruteForce(obstacleGrid,m,n,i,j+1);

    return down + right;
}
int memo(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>& dp) {
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(obstacleGrid[i][j] == 1) return 0;
    int down = memo(obstacleGrid,m,n,i+1,j,dp);
    int right = memo(obstacleGrid,m,n,i,j+1,dp);
    dp[i][j] = down + right;
    return down + right;
}
int tab(vector<vector<int>>& obstacleGrid, int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(int i=0;i<m;i++) {
        if(obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
    }
    for(int i=0;i<n;i++) {
        if(obstacleGrid[0][i] == 1) break;
        dp[0][i] = 1;
    }

    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            if(obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // int ans = bruteForce(obstacleGrid,m,n,0,0);
    vector<vector<int>> dp(m, vector<int>(n,-1));
    // int ans = memo(obstacleGrid,m,n,0,0,dp);    
    int ans = tab(obstacleGrid,m,n);
    cout << ans <<endl;
}