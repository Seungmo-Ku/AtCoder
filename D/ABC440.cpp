#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);

    for (int i = 0; i < N; i ++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int j = 0; j < Q; j ++) {
        long long X, Y;
        cin >> X >> Y;

        long long count_exist_before_X = lower_bound(A.begin(), A.end(), X) - A.begin();
        long long missing_before_X = (X - 1) - count_exist_before_X;

        long long K = Y + missing_before_X;

        long long low = 0, high = N;
        long long idx = N;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long missing_cnt = A[mid] - (mid + 1);

            if (missing_cnt >= K) {
                idx = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << K + idx << endl;
    }
    return 0;
}