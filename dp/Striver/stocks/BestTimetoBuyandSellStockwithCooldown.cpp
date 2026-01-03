#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    int bruteForce(vector<int>& prices, int i ) {

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

    }

    
    
};

int main() {
	Solution s;
    
	vector<int> prices = {3,3,5,0,0,3,1,4};
    
   
	cout << s.maxProfit(prices);
}
