#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<long long> A(N + 1), B(N + 1), C(N + 1), cumA(N + 1), cumB(N + 1), cumC(N + 1);

    for (int i = 1; i <= N; i ++) {
        cin >> A[i];
        if (i == 1) cumA[i] = A[i];
        else cumA[i] = cumA[i - 1] + A[i];
    }
    for (int i = 1; i <= N; i ++) {
        cin >> B[i];
        if (i == 1) cumB[i] = B[i];
        else cumB[i] = cumB[i - 1] + B[i];
    }
    for (int i = 1; i <= N; i ++) {
        cin >> C[i];
        if (i == 1) cumC[i] = C[i];
        else cumC[i] = cumC[i - 1] + C[i];
    }

    long long maxX = cumA[1] - cumB[1]; // 시작 값
    long long maxY = cumB[2] + cumC[N] - cumC[2];
    long long max = maxX + maxY;

    for (int y = 2; y < N; y ++) {
        long long newMaxX = cumA[y - 1] - cumB[y - 1];
        if (newMaxX > maxX) maxX = newMaxX;
        long long newMaxY = cumB[y] + cumC[N] - cumC[y];
        if (newMaxY + maxX > max) max = newMaxY + maxX;
    }

    cout << max << endl;

    return 0;
}