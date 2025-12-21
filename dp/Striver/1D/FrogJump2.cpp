#include<iostream>
using namespace std;



int tabulation(vector<int> &heights, int n, int k) {
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        
        for(int j=1;j<=k;j++) {
            if(i-j >= 0){
                dp[i] = min(dp[i], abs(heights[i] - heights[i - j]))
                    + dp[i - j];
            }
            
        }
    }
    return dp[n-1];
}

int main() {
    vector<int> heights = {2, 1, 3, 5, 4};
    
    int n = heights.size();
    int k = 3;

    int ans = tabulation(heights, n, k);
    
    cout << "Answer is : " << ans << endl;
}