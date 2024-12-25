#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100005;  // Định nghĩa kích thước dãy số
int n;
int a[MAX];  // Mảng lưu các phần tử của dãy số
int dp[MAX];  // Mảng lưu kết quả tối ưu

void inp() {
    cin >> n;  // Nhập số lượng phần tử trong dãy
    for(int i = 1; i <= n; i++) {
        cin >> a[i];  // Nhập các phần tử trong dãy số
    }
}

void proc() {
    if (n == 1) {  // Nếu chỉ có một phần tử, kết quả là phần tử đó
        cout << a[1] << endl;
        return;
    }

    // Khởi tạo giá trị cơ sở
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);

    // Dùng quy hoạch động để tính dp[i]
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);  // Công thức quy hoạch động
    }

    // In ra tổng lớn nhất tìm được
    cout << dp[n] << endl;
}

int main() {
    inp();  // Nhập dãy số
    proc();  // Tính và in kết quả
    return 0;
}
