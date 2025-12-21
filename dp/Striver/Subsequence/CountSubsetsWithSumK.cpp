#include <iostream>
using namespace std;

class Solution{
	public:
    int bruteForce(vector<int>&arr, int K, int i, int currSum) {
        if(currSum > K) return 0;
        if(i==arr.size()) {
            if(currSum == K) return 1;
            return 0;
        }
        
        int take = bruteForce(arr, K, i+1, currSum + arr[i]);
        int skip = bruteForce(arr, K, i+1, currSum);
        return take + skip;
    }
    int memo(vector<int>&arr, int K, int i, int currSum, vector<vector<int>>& dp) {
        if(currSum > K) return 0;
        if(i==arr.size()) {
            if(currSum == K) return 1;
            return 0;
        }
        
        if(dp[i][currSum] != -1) return dp[i][currSum];

        int take = memo(arr, K, i+1, currSum + arr[i], dp);
        int skip = memo(arr, K, i+1, currSum, dp);
        return dp[i][currSum] = take + skip;
    }
    int tab(vector<int>&arr, int K) {
        int n = arr.size();
        vector<vector<int>> dp(arr.size()+1, vector<int>(K+1,0));
        dp[n][K] = 1;

        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=K;j++) {
                int skip = dp[i+1][j];
                int take = 0;
                if(arr[i]+ j <= K) {
                    take = dp[i+1][j + arr[i]];
                }
                dp[i][j] = take + skip;
            }
        }
        return dp[0][0];

    }
	int perfectSum(vector<int>&arr, int K){
        vector<vector<int>> dp(arr.size()+1, vector<int>(K+1,-1));
        return tab(arr, K);
	}
};

int main() {
    Solution s;
    vector<int> arr = {2, 3, 5, 16, 8, 10};
    int K = 10;
    int ans = s.perfectSum(arr, K);
    cout << ans;
}