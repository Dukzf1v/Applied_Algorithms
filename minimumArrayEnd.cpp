#include <iostream>
#include <vector>
using namespace std;

long long minimumEnd(int n, int x) {
    long long last_element = x; 

    for (int i = 1; i < n; ++i) {
        last_element++;
        while ((last_element & x) != x) {
            last_element++;
        }
    }
    
    return last_element;
}

int main() {
    // Test case 1
    int n1 = 3, x1 = 4;
    cout << "Test Case 1 - Minimum End: " << minimumEnd(n1, x1) << endl;  // Expected Output: 6

    // Test case 2
    int n2 = 2, x2 = 7;
    cout << "Test Case 2 - Minimum End: " << minimumEnd(n2, x2) << endl;  // Expected Output: 15
    
    return 0;
}
