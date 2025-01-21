#include <iostream>

using namespace std;

int main(void) {

    string S;

    cin >> S;

    string ans = "No";

    if(S.length() == 3) {
        if(S.find('A') != string::npos && S.find('B') != string::npos && S.find('C') != string::npos) {
            ans = "Yes";
        }
    }

    cout << ans << endl;

    return 0;
}