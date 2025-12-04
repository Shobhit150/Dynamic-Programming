#include <iostream>
using namespace std;

int bruteForce(int m, int n, int i, int j) {
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;

    int right = bruteForce(m,n,i+1,j);
    int down = bruteForce(m,n,i,j+1);

    return right + down;
}
int memo(int m, int n, int i, int j, vector<vector<int>> &dp) {
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int right = memo(m,n,i+1,j, dp);
    int down = memo(m,n,i,j+1, dp);
    dp[i][j] = right + down;
    return right + down;
}
int tab(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,0));
    // for(int i=1;i<m;i++) dp[i][0] = 1;
    // for(int i=1;i<n;i++) dp[0][i] = 1;
    dp[0][0] = 1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(i == 0 && j == 0) continue;
            int up = 0;
            if(i>=1) up = dp[i-1][j];
            int down = 0;
            if(j>=1) down = dp[i][j-1];
            dp[i][j] = up+down;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m-1][n-1];
}
int tab2(int m, int n) {
    vector<int> dp(n,0);
    // for(int i=1;i<m;i++) dp[i][0] = 1;
    // for(int i=1;i<n;i++) dp[0][i] = 1;
    dp[0] = 1;
    for(int i=0;i<m;i++) {
        
        for(int j=0;j<n;j++) {
            if(i == 0 && j == 0) continue;
            int up = 0;
            if(i>=1) up = dp[j];
            int left = 0;
            if(j>=1) left = dp[j-1];
            dp[j] = up+left;
        }
       
    }
    
    return dp[n-1];
}
int main() {
    int m = 3;
    int n = 7;
    // vector<vector<int>> dp(m, vector<int>(n,-1));
    // int ans = bruteForce(m,n,0,0);
    // int ans = memo(m,n,0,0,dp);
    int ans = tab2(m,n);
    
    cout << ans <<endl;
}