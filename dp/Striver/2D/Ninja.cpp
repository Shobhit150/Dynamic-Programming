#include <iostream>
#include <vector>
using namespace std;

int bruteForce(vector<vector<int>> &matrix, int day, int last) {
    if(day == matrix.size()) {
        return 0;
    }
    int max1 = 0;

    for(int i=0;i<3;i++) {
        if(i!=last) {
            int point = matrix[day][i] + bruteForce(matrix, day+1, i);
            max1 = max(max1, point);
        }
    }
    return max1;
}
int memo(vector<vector<int>> &matrix, int day, int last, vector<vector<int>> &dp) {
    if(day == matrix.size()) {
        return 0;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int max1 = 0;

    for(int i=0;i<3;i++) {
        if(i!=last) {
            int point = matrix[day][i] + memo(matrix, day+1, i, dp);
            max1 = max(max1, point);
        }
    }
    dp[day][last] = max1;
    return max1;
}

int tab(vector<vector<int>> &matrix, int n) {
    vector<int> dp(4,0);

    for(int day=n-1;day>=0;day--) {
        vector<int> temp(4,0);
        for(int last = 0;last<4;last++) {
            temp[last] = 0;
            for(int task = 0;task<3;task++) {
                if(task != last) {
                    temp[last] = max(temp[last], matrix[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
int ninjaTraining(vector<vector<int>> &matrix) {
    // return bruteForce(matrix, 0, 3);
    int n = matrix.size();
    // vector<vector<int>> dp(n+1, vector<int>(4,-1));
    
    // return memo(matrix, 0, 3, dp);
    return tab(matrix, n);
    
}

int main(){
    vector<vector<int>> arr = {{90, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int ans = ninjaTraining(arr);
    cout << "Solution ans : " << ans << endl;
}