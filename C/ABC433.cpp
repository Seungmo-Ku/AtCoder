#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    int length = S.length();

    vector<pair<char, int>> stringGroups; // { char, count }

    int currentChar = S[0];
    int count = 1;
    for (int i = 1; i < length; i ++) { // 첫 번째는 기록하고 시작
        if (S[i] != currentChar) {
            stringGroups.push_back({ currentChar, count });
            currentChar = S[i];
            count = 1;
        } else {
            count ++;
        }
    }
    stringGroups.push_back({ currentChar, count });

    int size = stringGroups.size();
    int count1122 = 0;
    
    for (int i = 0; i < size - 1; i ++) {
        if (stringGroups[i].first + 1 == stringGroups[i + 1].first) {
            count1122 += min(stringGroups[i].second, stringGroups[i + 1].second);
        }
    }

    cout << count1122 << endl;

    return 0;
}