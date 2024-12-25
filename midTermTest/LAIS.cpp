#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
    int f1[n], f2[n]; 

    fill(f1, f1 + n, 1); 
    fill(f2, f2 + n, 1);

    int res = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(a[i]) > abs(a[j]) && a[i] * a[j] < 0) {
                if (a[i] > 0) { 
                    f1[i] = max(f1[i], f2[j] + 1);
                } else { 
                    f2[i] = max(f2[i], f1[j] + 1);
                }
            }
        }
        res = max(res, max(f1[i], f2[i]));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, n) << endl;
    return 0;
}

/*#include <iostream>
#include <vector>

using namespace std;

//Global Variables
int n = 0, res = 0;

vector <int> a;
vector <int> LAIS;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    cin >> n;  LAIS.resize(n + 1); a.resize(n + 1);

    for (int i = 1; i <= n; ++i){

        cin >> a[i];
    }

    for (int i = n; i >= 1; --i){

        LAIS[i] = 1;

        for (int j = i + 1; j <= n; ++j){

            if (a[j] * a[i] < 0 && abs(a[j]) > abs(a[i])){

                LAIS[i] = max(LAIS[i], LAIS[j] + 1);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i){

        res = max(res, LAIS[i]);
    }

    cout << res;

    return 0;
}*/
