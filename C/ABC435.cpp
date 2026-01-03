#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N; 
    cin >> N;

    vector<int> A(N + 1);

    for (int i = 0; i < N; i ++) {
        cin >> A[i + 1]; // 1 부터 시작
    }

    // i 번째가 무너지면 i + Ai - 1 까지 무너짐

    int collapseIndex = 1; // 현재 무너지고 있는 index
    int finalIndex = 1 + A[1] - 1; // 마지막으로 무너질 수 있는 index

    while (finalIndex >= collapseIndex && collapseIndex <= N) {
        int newCollapseIndex = collapseIndex + A[collapseIndex] - 1;
        finalIndex = newCollapseIndex > finalIndex ? newCollapseIndex : finalIndex;
        collapseIndex ++;
    }

    finalIndex = finalIndex > N ? N : finalIndex;
    cout << finalIndex << endl;

    return 0;
}