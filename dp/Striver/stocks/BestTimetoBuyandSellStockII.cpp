#include<iostream>

using namespace std;
class Solution {
public:
    int bruteForce(vector<int>& prices, int i, bool canBuy) {
        if(i == prices.size()) {
            if(canBuy) return 0;
            return INT_MIN;
        }

        if(canBuy) {
            return max( 0 + bruteForce(prices, i+1, canBuy), 
                    -prices[i] + bruteForce(prices, i+1, !canBuy));
        }
        return max( 0 + bruteForce(prices, i+1, canBuy), 
                    prices[i] + bruteForce(prices, i+1, !canBuy));
    }
    int maxProfit(vector<int>& prices) {
	return bruteForce(prices, 0, true); 
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
}
