#include<iostream>
using namespace std;

// int frogJump(vector<int>& heights) {
//     int n = heights.size();
//     vector<int> dp(n+1,0);
//     dp[1] = abs(heights[1] - heights[0]);
//     for(int i=2;i<n;i++) {
        
//         int left = dp[i-1] + abs(heights[i] - heights[i-1]);
//         int right = dp[i-2] + abs(heights[i] - heights[i-2]);
//         dp[i] = min(right, left);
//     }
//     for(int i=0;i<n;i++) {
//         cout << dp[i] << " ";
//     }
//     return dp[n-1];
// }

int bruteForce(vector<int>& heights, int currStone) {
    if(currStone == 0) {
        return 0;
    }
    if(currStone < 0) return INT_MAX/2;
    int left = abs(heights[currStone] - heights[currStone - 1]) + bruteForce(heights, currStone-1);
    int right = abs(heights[currStone] - heights[currStone - 2]) + bruteForce(heights, currStone-2);

    return min(left, right);
}

int memo(vector<int>& heights, int currStone, vector<int> &dp) {
    if(currStone == 0) {
        return 0;
    }
    
    if(dp[currStone] != -1) return dp[currStone];
    int left = abs(heights[currStone] - heights[currStone - 1]) 
                + bruteForce(heights, currStone-1);
    int right = INT_MAX;
    if(currStone > 1) {
            int right = abs(heights[currStone] - heights[currStone - 2]) 
                + bruteForce(heights, currStone-2);
    }
    dp[currStone] = min(left,right);
    return min(left, right);
}
int tabulation(vector<int> &heights, int n) {
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        int left = abs(heights[i] - heights[i - 1]) + dp[i-1];
        int right = INT_MAX;
        if(i>1) {
            right = abs(heights[i] - heights[i - 2]) + dp[i-2];
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}
int tabulation2(vector<int> &heights, int n) {
    
    int prev = 0;
    int prev2 = 0;

    for(int i=1;i<n;i++) {
        int left = abs(heights[i] - heights[i - 1]) + prev;
        int right = INT_MAX;
        if(i>1) {
            right = abs(heights[i] - heights[i - 2]) + prev2;
        }
        
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main() {
    vector<int> heights = {2, 1, 3, 5, 4};
    // int ans = frogJump(heights);
    int n = heights.size();
    // int ans = bruteForce(heights, n-1);
    // vector<int> dp(n+1, -1);
    // int ans = memo(heights, n-1, dp);
    int ans = tabulation2(heights, n);
    
    cout << "Answer is : " << ans << endl;
}