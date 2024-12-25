#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> classesForTeacher[50]; // Các lớp mà mỗi giảng viên có thể dạy
vector<int> assignedClasses[50]; // Lớp đã được phân cho mỗi giảng viên
int conflictMatrix[50][50]; // conflictMatrix[i][j] = 1 nếu lớp i và lớp j xung đột
int credits[50]; // Số tín chỉ mỗi lớp
int minClasses[50]; // Số lớp tối thiểu mỗi giảng viên phải nhận
int teacherLoad[50]; // Tổng tín chỉ của mỗi giảng viên
int minMaxLoad = INT_MAX;

// Kiểm tra xem lớp cls có thể phân cho giảng viên teacher không
bool isValid(int teacher, int cls) {
    for (int assignedClass : assignedClasses[teacher]) {
        if (conflictMatrix[assignedClass][cls]) return false;
    }
    return true;
}

// Kiểm tra tất cả giảng viên có đáp ứng số lớp tối thiểu không
bool isAllocationValid() {
    for (int i = 1; i <= m; i++) {
        if ((int)assignedClasses[i].size() < minClasses[i]) return false;
    }
    return true;
}

// Backtracking để phân lớp
void assignClass(int cls) {
    if (cls > n) {
        if (isAllocationValid()) {
            int currentMaxLoad = *max_element(teacherLoad + 1, teacherLoad + m + 1);
            minMaxLoad = min(minMaxLoad, currentMaxLoad);
        }
        return;
    }

    for (int teacher : classesForTeacher[cls]) {
        if (isValid(teacher, cls)) {
            // Cập nhật trạng thái
            teacherLoad[teacher] += credits[cls];
            assignedClasses[teacher].push_back(cls);

            // Đệ quy cho lớp tiếp theo
            assignClass(cls + 1);

            // Quay lui
            teacherLoad[teacher] -= credits[cls];
            assignedClasses[teacher].pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        while (k--) {
            int cls; cin >> cls;
            classesForTeacher[cls].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) cin >> credits[i];
    for (int i = 1; i <= m; i++) cin >> minClasses[i];

    int conflicts; cin >> conflicts;
    while (conflicts--) {
        int u, v; cin >> u >> v;
        conflictMatrix[u][v] = conflictMatrix[v][u] = 1;
    }

    assignClass(1);

    if (minMaxLoad != INT_MAX) cout << minMaxLoad << "\n";
    else cout << "-1\n";

    return 0;
}