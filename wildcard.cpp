#include <iostream>
#include <string>
using namespace std;

class Solution_greedy {
public:
    bool isMatch(string s, string p) {
        int p1 = 0, p2 = 0;
        int starIndex = -1;  
        int matchIndex = 0;  
        
        while (p1 < s.size()) {
            if (p[p2] == '*') {
                starIndex = p2;
                matchIndex = p1;
                p2++; 
            }

            else if (p2 < p.size() && (p[p2] == s[p1] || p[p2] == '?')) {
                p1++;
                p2++;
            }

            else if (starIndex != -1) {
                p2 = starIndex + 1; 
                p1 = ++matchIndex;    
            }

            else {
                return false;
            }
        }
        while (p2 < p.size() && p[p2] == '*') {
            p2++;  
        }

        return p2 == p.size();  
    }
};

int main(){
    Solution_greedy sol;
    string s, p;
    getline(cin, s);
    getline(cin, p);
    sol.isMatch(s,p) ? cout << "True" : cout << "False";
    return 0;
}