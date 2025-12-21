#include<iostream>
using namespace std;



int main() {
    vector<int> cost = {4,3,2,5,6,7,2,5,5};
    int target = 1;
    Solution s;
    auto res = s.largestNumber(cost, target);
    cout << res;


}