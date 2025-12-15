

#include<iostream>
using namespace std;

class Solution{
    public:
    int memo(vector<int> price, int n, vector<int> &dp) {
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, price[i-1] + memo(price, n-i, dp));
        }
        return dp[n] = ans;
    }
    int tab(vector<int> price, int n) {
        

        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++) {
            int ans = 0;
            for(int j=1;j<=i;j++) {
                ans = max(ans, price[j-1] + dp[i-j]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }

    int bruteForce(vector<int> price, int n) {
        if(n==0) return 0;

        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, price[i-1] + bruteForce(price, n-i));
        }
        return ans;
    }
    int best = 0;
    vector<int> res;
    int backtrack(vector<int>& price, int n, int currVal, vector<int> &curr) {
        if(n==0) {
            if(currVal > best) {
                best = currVal;
                res = curr;
            }
            return 0;
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            curr.push_back(i);
            ans = max(ans, price[i-1] + backtrack(price, n-i, currVal + price[i-1], curr));
            curr.pop_back();
        }
        return ans;
    }
    int rodCutting(vector<int> price, int n) {
        vector<int> dp(n+1, -1);
        // int ans = backtrack(price, n, 0, curr);
        
        // for(int i=0;i<res.size();i++) {
        //     cout << res[i] << " ";
        // }
        // cout << endl;
        return tab(price, n);
    }
};

int main() {
    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int N = 8;

    Solution s;
    cout << s.rodCutting(price, N);

    return 0;
}
