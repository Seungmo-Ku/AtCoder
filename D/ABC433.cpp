#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int numLength(int number) {
    return to_string(number).length();
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i ++) {
        cin >> A[i];
    }

    sort (A.begin(), A.end());

    long long output = 0;

    for (int len = 1; len <= 10; len ++) { // 한 자리 ~ 열 자리 까지
        map<long long, int> remainderCount;
        for (int i = 0; i < N; i ++) {
            if (numLength(A[i]) == len) {
                remainderCount[A[i] % M] ++;
            }
        }

        if (remainderCount.empty()) continue;

        for (int i = 0; i < N; i ++) {
            long long aPow = pow(10, len);
            long long powRemainder = aPow % M;
            long long remainder = (long long) ((powRemainder * A[i]) % M);
            long long neededRemainder = (M - remainder) % M;
            if (remainderCount.count(neededRemainder)) {
                output += remainderCount[neededRemainder];
            }
        }
    }

    cout << output << endl;

    return 0;
}