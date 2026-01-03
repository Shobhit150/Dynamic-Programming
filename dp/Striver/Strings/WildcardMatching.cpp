#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool bruteForce(string& s, string& p, int i, int j) {
         
        if(i==0 && j==0) return true;
        if(j==0) return false;

        if(i==0) {
            if(p[j-1] == '*') {
                return bruteForce(s,p,i,j-1);
            }
            return false;
        }

        if(s[i-1] == p[j-1] || p[j-1] == '?') {
            return bruteForce(s,p,i-1,j-1);
        }
        if(p[j-1] == '*') {
            return bruteForce(s,p,i-1,j) ||
                    bruteForce(s,p,i,j-1);
        } 
        return false;

    }
    bool memo(string& s, string& p, int i, int j, vector<vector<int>> &dp) {
         
        if(i==0 && j==0) return dp[i][j] = true;;
        if(j==0) return dp[i][j] = false;;
        if(dp[i][j] != -1) return dp[i][j];

        if(i==0) {
            if(p[j-1] == '*') {
                return memo(s,p,i,j-1, dp);
            }
            return dp[i][j] = false;
        }

        if(s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j] = memo(s, p, i-1, j-1, dp);
        }
        if(p[j-1] == '*') {
            return dp[i][j] = memo(s, p, i-1, j, dp) ||
                          memo(s, p, i, j-1, dp);
        } 
        return dp[i][j] = false;

    }
    bool tab(string& s, string& p, int m, int n) {
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));

        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                } 
                else if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];

                } 
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];

        
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return memo(s,p,m,n, dp);
    }
};

int main() {
    Solution s1;
    string s = "adceb";
    string p = "*a*b";
    cout << s1.isMatch(s,p);
}