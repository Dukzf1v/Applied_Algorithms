#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0, total_cost = 0;
        int current_gas = 0;
        int start_index = 0;

        for (int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];

            if (current_gas < 0) {
                start_index = i + 1; 
                current_gas = 0; 
            }
        }

        if (total_gas < total_cost) {
            return -1;
        }
        return start_index;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) << endl; 
    return 0;
}
