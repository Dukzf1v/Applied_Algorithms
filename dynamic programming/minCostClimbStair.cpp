    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n,0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for(int i = 2; i < n; i++){
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
            }
            return min(dp[n-1],dp[n-2]);
        }
    };

    int main(){
        Solution solution;
        vector<int> cost = {10,15,20};
        cout << solution.minCostClimbingStairs(cost);
        return 0;
    }

