#include<iostream>
using namespace std;

class Solution {
public:
    string ans = "";

    void bruteForce(vector<int>& cost, int target, string temp) {
        if (target == 0) {
            if (temp.size() > ans.size() || 
            (temp.size() == ans.size() && temp > ans)) {
                ans = temp;
            }
            return;
        };
        for(int i=0;i<9;i++) {
            if(cost[i] <= target) {
                bruteForce(cost, target - cost[i], char('1'+i) + temp);
            }
        }
    }
    string memo(vector<int>& cost, int target, vector<string>&dp) {
        if (target == 0) {
            return "";
        };
        if(dp[target] != "#") return dp[target];
        string best = "#";
        for(int i=0;i<9;i++) {
            if(cost[i] <= target) {
                // bruteForce(cost, target - cost[i], char('1'+i) + temp);
                string curr = memo(cost, target - cost[i], dp);
                if(curr != "#" && (curr.size() + 1 > best.size() || (curr.size()+1 == best.size() && (char)('1'+i) + curr > best))) {
                    best = (char)('1'+i) + curr;
                }
            }
        }
        best = best== "" ? "#" : best;
        return dp[target] = best;

    }
    string largestNumber(vector<int>& cost, int target) {
        // string s = "";
        // bruteForce(cost, target, s);
        // return ans;
        vector<string> dp(target+1, "#");
        return memo(cost, target, dp);
    }
};

int main() {
    vector<int> cost = {4,3,2,5,6,7,2,5,5};
    int target = 1;
    Solution s;
    auto res = s.largestNumber(cost, target);
    cout << res;


}