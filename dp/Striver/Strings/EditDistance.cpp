#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int bruteForce(string& word1, string& word2, int i, int j) {
        if(i==word1.size()) {
            return word2.size() - j;
        }
        if(j==word2.size()) {
            return word1.size() - i;
        }

        if(word1[i] == word2[j]) {
            return bruteForce(word1, word2, i+1, j+1);
        }

        int insertop = 1 + bruteForce(word1, word2, i, j+1);
        int deleteop = 1 + bruteForce(word1, word2, i+1, j);
        int replaceops = 1 + bruteForce(word1, word2, i+1, j+1);
        return min({insertop, deleteop, replaceops});
    }
    int tab(string& word1, string& word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0;i<=n;i++) {
            dp[m][i] = n - i;
        }
        for(int i=0;i<=m;i++) {
            dp[i][n] = m - i;
        }
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j+1],
                        dp[i+1][j],
                        dp[i+1][j+1]
                    });
                }
                
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return tab(word1, word2);
    }
};

int main() {
    Solution s1;
    string s = "babgbag";
    string t = "bag";
    cout << s1.minDistance(s,t);
}