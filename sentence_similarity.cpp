#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream> // Thư viện để xử lý chuỗi
using namespace std;

class Solution {
public:
    // Hàm kiểm tra xem hai câu có tương tự nhau hay không
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Nếu hai câu có độ dài bằng nhau, so sánh trực tiếp
        if (sentence1.length() == sentence2.length())
            return sentence1 == sentence2;

        // Chia các câu thành các từ
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        const int m = words1.size(); // Số lượng từ trong sentence1
        const int n = words2.size(); // Số lượng từ trong sentence2
        
        if (m > n)
            return areSentencesSimilar(sentence2, sentence1);

        int i = 0; // Chỉ số cho words1
        // So sánh các từ ở phần đầu
        while (i < m && words1[i] == words2[i])
            ++i;

        // So sánh các từ ở phần cuối
        while (i < m && words1[i] == words2[i + n - m])
            ++i;

        // Kiểm tra xem tất cả các từ của words1 đã khớp chưa
        return i == m;
    }

private:
    // Hàm tách một chuỗi thành các từ
    vector<string> split(const string& sentence) {
        vector<string> words; // Vector chứa các từ
        istringstream iss(sentence); // Sử dụng istringstream để tách chuỗi

        // Tách từng từ và thêm vào vector
        for (string s; iss >> s;)
            words.push_back(s);

        return words; // Trả về vector chứa các từ
    }
};

// Hàm main để kiểm tra
int main() {
    Solution solution;

    // Ví dụ kiểm tra
    string sentence1 = "Hello my name is Jane";
    string sentence2 = "Hello Jane";
    
    bool result1 = solution.areSentencesSimilar(sentence1, sentence2);
    cout << (result1 ? "True" : "False") << endl; // Kết quả: True

    sentence1 = "Frog cool";
    sentence2 = "Frogs are cool";
    
    bool result2 = solution.areSentencesSimilar(sentence1, sentence2);
    cout << (result2 ? "True" : "False") << endl; // Kết quả: False

    sentence1 = "A B C";
    sentence2 = "A X Y Z B C";
    
    bool result3 = solution.areSentencesSimilar(sentence1, sentence2);
    cout << (result3 ? "True" : "False") << endl; // Kết quả: True

    return 0;
}
