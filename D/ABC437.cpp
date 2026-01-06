#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

// int findIndex(int element, vector<int>& numVector) {
//     int start = 0, end = numVector.size();
//     int idx = (start + end) / 2;
//     while (element != numVector[idx]) {
//         if (element > numVector[idx]) {
//             start = idx + 1;
//         } else if (element < numVector[idx]) {
//             end = idx - 1;
//         }
//         if (idx == (start + end) / 2) {
//             return idx;
//         }
//         idx = (start + end) / 2;
//     }
//     return idx;
// }

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    
    for (int i = 0; i < N; i ++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i ++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end()); //NlogN

    vector<long long> psum(M + 1, 0);

    for (int i = 0; i < M; i++) {
        psum[i + 1] = (psum[i] + B[i]) % MOD;
    }

    long long sum = 0;

    for (int i = 0; i < N; i ++) {
        int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        
        long long smallCount = idx;
        long long sumSmallB = psum[idx];
        
        long long term1 = (smallCount * A[i]) % MOD; // A[i] 더해주기
        term1 = (term1 - sumSmallB + MOD) % MOD; // A[i] 보다 작은 B 빼기

        long long largeCount = M - idx; // 빼야 하는 A[i] 갯수
        long long sumLargeB = (psum[M] - psum[idx] + MOD) % MOD;
        
        long long term2 = (sumLargeB - (largeCount * A[i]) % MOD + MOD) % MOD;

        sum = (sum + term1 + term2) % MOD;
    } // 1 3 5 7 

    cout << sum << endl;

    return 0;
}