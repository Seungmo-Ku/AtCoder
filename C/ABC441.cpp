#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, K;
    long long X;

    cin >> N >> K >> X;

    vector<long long> A(N);

    for (int i = 0; i < N; i ++) {
        cin >> A[i];
    }

    int numberOfWater = N - K;

    // 입력 받을 때 뭐가 사케인지 모르니까 sake 가 오름차순 정렬 했을 때 앞의 K 개 라고 가정
    sort(A.rbegin(), A.rend());

    A.erase(A.begin(), A.begin() + numberOfWater);

    long long currentMl = 0;
    int count = 0;
    
    for (auto ml : A) {
        currentMl += ml;
        count ++;
        if (currentMl >= X) {
            cout << numberOfWater + count << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    

    // 보장되는 최소한의 컵의 갯수니까 전체에서 가장 큰 N - K  개의 컵을 물이라고 가정하고 제거. 그 후 큰 순서대로 마시면서 counting
    return 0;
}