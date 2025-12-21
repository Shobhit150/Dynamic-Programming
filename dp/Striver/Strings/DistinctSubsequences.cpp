#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:

    int bruteForce(string& s, string& t, int m, int n, int i, int j) {
        if(j<0) {
            return 1;
        }
        if(i<0) return 0;
        int ans = 0;
        if(s[i] == t[j]) {
            ans += bruteForce(s,t,m,n,i-1,j-1);
        }
        ans += bruteForce(s,t,m,n,i-1,j);
        return ans;
    }
    int memo(string& s, string& t, int i, int j, vector<vector<int>> &dp) {
       if(j==0) {
            return 1;
        }
        if(i==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i-1] == t[j-1]) {
            ans += memo(s,t,i-1,j-1,dp);
        }
        ans += memo(s,t,i-1,j,dp);
        return dp[i][j] = ans;
    }
    int tab(string& s, string& t, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<=m;i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                int ans = 0;
                if(s[i-1] == t[j-1]) {
                    ans += dp[i-1][j-1];
                }
                ans += dp[i-1][j];
                dp[i][j] = ans;
            }
        }
        return dp[m][n];
    }
    

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return tab(s,t,m,n);


        // for(int i=1;i<=m;i++) {
        //     for(int j=1;j<=n;j++) {
        //         if(s[i-1] == t[j-1]) {
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //             continue;
        //         }
        //         int right = dp[i][j-1];
        //         int top = dp[i-1][j];
        //         dp[i][j] = max(right, top);
        //     }
        // }
        // if(dp[m][n] != n) return -1;

        // for(int i=0;i<=m;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        // return -1;
    }
};
int main() {
    Solution s1;
    string s = "babgbag";
    string t = "bag";
    cout << s1.numDistinct(s,t);
}