#include <iostream>
using namespace std;

bool bruteForce(vector<int> &arr, int target, int i) {
    if(target == 0) return true;
    if(target < 0) return false;
    if(i==arr.size()) {
        return false;
    }

    bool ans = bruteForce(arr, target - arr[i], i+1);
    ans |= bruteForce(arr, target, i+1);
    return ans;
}
bool memo(vector<int> &arr, int target, int i, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(i==arr.size()) {
        return false;
    }
    if(target < 0) return false;
    if(dp[i][target] != -1) return dp[i][target];
    

    bool ans = memo(arr, target - arr[i], i+1,dp);
    ans |= memo(arr, target, i+1,dp);
    dp[i][target] = ans;
    return ans;
}
bool tab(vector<int> &arr, int n, int target) {
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    
    

    for(int i=0;i<=n;i++) {
        dp[i][0] = true;
    }
    

    for(int i=n-1;i>=0;i--) {
        for(int j=1;j<=target;j++) {
            // bool ans = dp[i][target-arr[i]];
            // ans |= dp[i][target];
            // dp[i][target]= ans;

            bool skip = dp[i+1][j];
            bool take = false;
            if(j-arr[i] >= 0) {
                take = dp[i+1][j-arr[i]];
            }
            dp[i][j] = skip | take;
        }
    }
    return dp[0][target];
}
int main() {
    vector<int> arr = {1, 2, 7, 3};
    int n = arr.size();
    int target = 6;
    // vector<vector<int>> dp(n, vector<int>(target+1, -1));
    if(tab(arr,n,target)) cout << "True";
    else cout << "False";
}