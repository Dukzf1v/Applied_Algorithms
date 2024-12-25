#include <iostream>
#include <map>
using namespace std;

bool checkphone(string phoneNumber) {
    if (phoneNumber.length() == 0) {
        return false;  
    }
    for (int i = 0; i < phoneNumber.length(); i++) {
        if (!isdigit(phoneNumber[i])) {
            return false;  
        }
    }
    return true;
}

int time_duration(string ftime, string etime) {
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') +
                    60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') + 
                    ((ftime[6] - '0') * 10 + ftime[7] - '0');
    int endTime =   3600 * ((etime[0] - '0') * 10 + etime[1] - '0') +
                    60 * ((etime[3] - '0') * 10 + etime[4] - '0') + 
                    ((etime[6] - '0') * 10 + etime[7] - '0');
    return endTime - startTime;
}

map<string, int> numberCalls, TimeCall;

int main() {
    string type, fnum, tnum, date, ftime, etime;
    int InNum = 0;
    map<string, int> PhoneCount;  
    int call_count = 0;

    while (true) {
        cin >> type;
        if (type == "#") break;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        
        if (!checkphone(fnum) || !checkphone(tnum)) {
            InNum++;
        }

        call_count++;
        PhoneCount[fnum]++;  
        TimeCall[fnum] += time_duration(ftime, etime); 
    }

    while (true) {
        cin >> type;
        if (type == "#") {
            break;
        }
        if (type == "?check_phone_number") {
            cout << (InNum == 0 ? 1 : 0) << endl;
        }
        if (type == "?number_calls_from") {
            string phone;
            cin >> phone;
            cout << PhoneCount[phone] << endl;
        }
        if (type == "?number_total_calls") {
            cout << call_count << endl;
        }
        if (type == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << TimeCall[phone] << endl;
        }
    }

    return 0;
}
