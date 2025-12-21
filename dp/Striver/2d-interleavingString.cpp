#include<iostream>
using namespace std;

bool backtrack(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp) {
    if(k==s3.size()) {
        return i == s1.size() && j == s2.size();
    }
    if(dp[i][j] != -1) return dp[i][j]; 

    int ans = 0;
    if(i<s1.size() && s1[i] == s3[k]) {
        ans |= backtrack(s1,s2,s3,i+1,j,k+1, dp);
            
    }
    
    
    if(j<s2.size() && s2[j] == s3[k]) {
        ans |= backtrack(s1,s2,s3,i,j+1,k+1, dp);
    }
    
    return dp[i][j] = ans;

}

bool isInterleave(string &s1, string &s2, string &s3) {
    vector<vector<int>> dp(s1.size() +1, vector<int>(s2.size()+1, -1));

     

    bool ans = backtrack(s1,s2,s3,0,0,0, dp);
    // print after complete computation
    for(int i=0;i<=s1.size();i++) {
        for(int j=0;j<=s2.size();j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool res = isInterleave(s1,s2,s3);
    if(res) {
        cout << "True";
    }else {
        cout << "False";
    }

}