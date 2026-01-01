#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int doCase() {
    int N;

    cin >> N;

    vector<long long> WP(N);

    long long totalPower = 0;

    for (int i = 0; i < N; i ++) {
        long long Wi, Pi;
        cin >> Wi >> Pi;
        totalPower += Pi;
        WP[i] = Wi + Pi;
    }

    sort(WP.begin(), WP.end());

    long long currentWP = 0;

    int index = 0;

    while (totalPower >= currentWP) {
        currentWP += WP[index ++];
    } 

    return index - 1;
}

int main(void) {

    int T;
    cin >> T;

    vector<int> output;

    for (int i = 0; i < T; i ++) {
        output.push_back(doCase());
    }

    for (auto result : output) {
        cout << result << endl;
    }
    return 0;
}