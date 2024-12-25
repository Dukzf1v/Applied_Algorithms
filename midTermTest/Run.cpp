/* Dãy số nguyên a = a1, a2, . . . , an cắt thành các đoạn con các phần tử liên tiếp, mỗi đoạn là một dãy tăng. 
   Tính xem phải cắt a thành ít nhất bao nhiêu đoạn
-------------------------------------------------------------------
Dữ liệu vào
• Dòng đầu chứa số nguyên dương n (1 ≤ n ≤ 105
)
• Dòng tiếp theo chứa n số nguyên dương a1 a2 . . . an (0 ≤ ai ≤ 109
)
Kết quả
Ghi một số nguyên duy nhất là số ít nhất các đoạn con tăng của a.
-------------------------------------------------------------------
Ví dụ
6
3 6 1 7 8 2

3
Giải thích
Dãy a được cắt thành (3,6), (1,7,8), (2)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i< n; i++){
        if(a[i] > a[i+1]){
            count++;
        }
    }
    cout << count;
    return 0;
}
