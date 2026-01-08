#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> count(N + 1, 0);
    for (int x = 1; x * x * 2 < N; x ++) {
        for (int y = x + 1; ; y ++) {
            long long sum = (long long) x * x + (long long) y * y;

            if (sum > N) break;
            count[sum] ++;
        }
    }

    vector<int> goodIntegers;

    for (int i = 1; i <= N; i ++) {
        if (count[i] == 1) {
            goodIntegers.push_back(i);
        }
    }

    cout << goodIntegers.size() << endl;
    for (auto goodInt : goodIntegers) {
        cout << goodInt << " ";
    } cout << endl;

    return 0;
}