#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int profit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] >= prices[i+1]){
                continue;
            }
            profit += prices[i+1] - prices[i];
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices);
    return 0;
}