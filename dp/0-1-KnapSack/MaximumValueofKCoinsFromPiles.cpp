#include <iostream>
using namespace std;
class Solution {
public:
    int max1 = 0;
    void bruteForce(vector<vector<int>>& piles, int k, int i, int curr) {
        if(k==0 || i==piles.size()) {
            max1 = max(max1, curr);
            return;
        }
        
        bruteForce(piles, k, i+1, curr);
        int sum = 0;

        for(int j=0;j<piles[i].size() && j<k;j++) {
            sum += piles[i][j];
            bruteForce(piles, k-(j+1), i+1, curr + sum);
        }
    }
    int memorization(vector<vector<int>>& piles, int k, int i, vector<vector<int>>& dp) {
        if(k==0 || i==piles.size()) {
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        
        
        int max1 = memorization(piles, k, i+1, dp);
        int sum = 0;

        for(int j=0;j<piles[i].size() && j<k;j++) {
            sum += piles[i][j];
            max1 = max(sum + memorization(piles, k-(j+1), i+1, dp), max1);
        }
        dp[i][k] = max1;
        return max1;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // bruteForce(piles, k,0,0);
        // return max1;

        vector<vector<int>> dp(piles.size()+1, vector<int>(k+1, -1));
        return memorization(piles, k, 0, dp);

    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{1,100,3}, {7,8,9}};
    int k = 2;
    cout << s.maxValueOfCoins(nums, k);
}
