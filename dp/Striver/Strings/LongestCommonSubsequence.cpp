#include <iostream>
using namespace std;

class Solution {
    public:
    int bruteForce(string str1, string str2, int i, int j, int m, int n) {
        if(i==m || j==n) return 0;
        if(str1[i] == str2[j]) {
            return 1 + bruteForce(str1, str2, i + 1, j + 1, m, n);
        }
        int left = bruteForce(str1, str2, i + 1, j, m, n);
        int right = bruteForce(str1, str2, i, j + 1, m, n);
        return max(left, right);

    }
    int memo(string str1, string str2, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i==-1 || j==-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(str1[i] == str2[j]) {
            return 1 + memo(str1, str2, i - 1, j - 1, m, n, dp);
        }
        int left = memo(str1, str2, i - 1, j, m, n, dp);
        int right = memo(str1, str2, i, j - 1, m, n, dp);
        return dp[i][j] = max(left, right);

    }
    int tab(string str1, string str2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }
                int left = dp[i-1][j];
                int right = dp[i][j-1];
                dp[i][j] = max(left, right);
            }
        }
        return dp[m][n];
    }
    int lcs(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return tab(str1, str2, m, n);
    }
};

int main() {
    Solution s;
    string str1 = "bdefgmnop";
    string str2 = "bfgmnop";
    cout << s.lcs(str1, str2);
}