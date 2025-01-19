#include <iostream>

using namespace std;

int main(void) {

    int N, C;
    cin >> N >> C;

    int* T = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    int candyCount = 1;
    int lastCandySec = T[0];

    for(int i = 1; i < N; i ++) {
        if(T[i] - lastCandySec >= C) {
            candyCount ++;
            lastCandySec = T[i];
        }
    }


    cout << candyCount << endl;

    delete[] T;

    return 0;

}